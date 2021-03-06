#include "HyperGraphManager.h"

#include<fstream>
#include<iostream>
#include<Distributions/uniform.h>

std::vector<int> HyperGraphManager::CalculateKTable(const HyperGraph& hyperGraph)noexcept
{
    std::vector<int> kTable(hyperGraph.GetNumberOfVertices());
    for(auto&& hyperedge : hyperGraph.GetHyperEdgeList())
    {
        for(auto&& vertex :  hyperedge)
        {
            kTable[vertex] += 1;
        }
    }
    return kTable;
}

std::vector<int> HyperGraphManager::CalculatePTable(const HyperEdgeList& hyperGraph)noexcept
{
    std::vector<int> pTable;
    pTable.reserve(hyperGraph.size());
    for(auto&& hyperEdge : hyperGraph)
    {
        pTable.emplace_back(hyperEdge.size());
    }
    return pTable;
}

void HyperGraphManager::MakeLoops(HyperGraph &hyperGraph,int vertexId,int amount)noexcept
{
    for(int i=0 ;i<amount;++i)
    {
        hyperGraph.AddHyperEdge({vertexId});
    }
}

std::vector<int> HyperGraphManager::KTableFromFile(const std::string& nameOfFile)noexcept
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
                std::cerr<<"Error : end of file reach but not all vertexes was set up";
                break;
            }
        }
        file.close();
    }
    else
    {
        std::cerr<<"Error : file dont exist :" << nameOfFile << std::endl;
    }
    return kTable;

}

void HyperGraphManager::HyperGraphToFile(const HyperGraph &hyperGraph , const std::string& nameOfFile)noexcept
{
    std::ofstream file (nameOfFile);
    if(file.is_open())
    {
        file<<hyperGraph.GetNumberOfVertices()<<'\n';
        file<<hyperGraph.size()<<'\n';
        for(auto const& hyperedge : hyperGraph.GetHyperEdgeList())
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

HyperGraph HyperGraphManager::HyperGraphFromFile(const std::string& nameOfFile)noexcept
{
    std::ifstream file (nameOfFile);
    HyperGraph hyperGraph;
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
            HyperEdge hyperedge;
            for(int i=0 ; i < sizeOfHyperedge ; ++i)
            {
                int vertex = 0;
                if(file >> vertex)
                {
                    hyperedge.insert(vertex);
                }
                else
                {
                    std::cerr<<"Error";
                    break;
                }
            }
            hyperGraph.AddHyperEdge(std::move(hyperedge));
        }
        file.close();
    }
    else
    {
        std::cerr<<"Error : file dont exist :" << nameOfFile << std::endl;
    }
    return hyperGraph;
}

std::map<HyperEdge,int> HyperGraphManager::CalculateHyperedgeDuplicates(const HyperEdgeList& hyperGraph)noexcept
{
    std::map<HyperEdge,int> hyperEdgeHistogram;
    for(auto const& hyperEdge : hyperGraph)
    {
         ++hyperEdgeHistogram[hyperEdge];
    }
    return hyperEdgeHistogram;
}

void HyperGraphManager::ShowHyperedgeDuplicates(const std::map<HyperEdge,int>& hyperGraphDuplicates)noexcept
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
