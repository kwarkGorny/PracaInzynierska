#include "AdjacencyListManager.h"

#include<fstream>
#include<iostream>


std::vector<int> AdjacencyListManager::CalculateKTable(const AdjacencyList& hyperGraph)
{
  std::vector<int> kTable(hyperGraph.GetNumberOfVertices());
  for(auto&& hyperedge : hyperGraph.GetAdjacencyList())
  {
    for(auto&& vertex :  hyperedge)
    {
        kTable[vertex] += 1;
    }
  }
  return kTable;
}

std::vector<int> AdjacencyListManager::CalculatePTable(const std::vector<std::set<int>>& hyperGraph)
{
   std::vector<int> pTable(hyperGraph.size());
   for(size_t i = 0; i < hyperGraph.size(); ++i)
   {
        pTable[i] += hyperGraph[i].size();
   }
   return pTable;
}

void AdjacencyListManager::MakeLoops(AdjacencyList &hyperGraph,int vertexId,int amount)
{
    for(int i=0 ;i<amount;++i)
    {
        hyperGraph.AddHyperEdge({vertexId});
    }
}

std::vector<int> AdjacencyListManager::KTableFromFile(const std::string& nameOfFile)
{
    std::ifstream file (nameOfFile);
    std::vector<int> kTable;

    if(file.is_open())
    {
        int numberOfVertices =0;
        file>>numberOfVertices;
        kTable.reserve(numberOfVertices);

        for(int i =0;i<numberOfVertices;++i)
        {
            int k=0;
            if(file>>k)
            {
                kTable.emplace_back(std::move(k));
            }
            else
            {
                std::cout<<"Error : end of file reach but not all vertexes was set up";
            }
        }
        file.close();
    }
    else
    {
        std::cout<<"Error : file dont exist";
    }
    return kTable;

}

void AdjacencyListManager::AdjacenyListToFile(const AdjacencyList &hyperGraph , const std::string& nameOfFile)
{
    std::ofstream file (nameOfFile);
    if(file.is_open())
    {
        file<<hyperGraph.GetNumberOfVertices()<<'\n';
        file<<hyperGraph.size()<<'\n';
        for(auto const& hyperedge : hyperGraph.GetAdjacencyList())
        {
            file<<hyperedge.size()<<'\n';
            for(auto const& vertex:hyperedge)
            {
                file<<vertex<<" ";
            }
            file<<'\n';
        }
        file.flush();
        file.close();
    }
}

AdjacencyList AdjacencyListManager::AdjacenyListFromFile(const std::string& nameOfFile)
{
    std::ifstream file (nameOfFile);
    AdjacencyList hyperGraph;
    if(file.is_open())
    {
        int numberOfVertices =0;
        int numberOfHyperedges =0;
        file>>numberOfVertices;
        hyperGraph.AddVerticies(numberOfVertices);

        file>>numberOfHyperedges;
        int sizeOfHyperedge =0;
        while(file >> sizeOfHyperedge)
        {
            std::set<int> hyperedge;
            for(int i=0 ; i < sizeOfHyperedge ; ++i)
            {
                int vertex = 0;
                if(file >> vertex)
                {
                    hyperedge.insert(vertex);
                }
                else
                {
                    std::cout<<"Error";
                }
            }
            hyperGraph.AddHyperEdge(std::move(hyperedge));
        }
        file.close();
    }
    else
    {
        std::cout<<"Error : file dont exist";
    }
    return hyperGraph;
}

std::map<std::set<int>,int> AdjacencyListManager::CalculateHyperedgeDuplicates(const std::vector<std::set<int>>& hyperGraph)
{
   std::map<std::set<int>,int> hyperEdgeHistogram;
   for(auto const& hyperEdge : hyperGraph)
   {
        ++hyperEdgeHistogram[hyperEdge];
   }
   return hyperEdgeHistogram;
}

void AdjacencyListManager::ShowHyperedgeDuplicates(const std::map<std::set<int>,int>& hyperGraphDuplicates)
{
    bool noDuplicates = true;
    for(auto && hyperEdge : hyperGraphDuplicates)
    {
        if(hyperEdge.second>1)
        {
            noDuplicates = false;
            for(auto && vertex : hyperEdge.first)
            {
                 std::cout<<vertex << " " ;
             }
            std::cout<< " dupicate: " << hyperEdge.second << " \n" ;
        }
    }
    if(noDuplicates)
    {
         std::cout<< "No Dupicates  \n" ;
    }
}
