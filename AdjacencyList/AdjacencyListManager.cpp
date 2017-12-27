#include "AdjacencyListManager.h"

#include<fstream>
#include<iostream>

AdjacencyListManager::AdjacencyListManager()
{

}

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
