#include "hypergraphmanager.h"
#include<vector>
#include<numeric>
HyperGraphManager::HyperGraphManager()
{
}

double HyperGraphManager::calculateAverageK(const IncidencyMatrix& hyperGraph)
{
    auto kTable=calculateKTable(hyperGraph);
    double av= std::accumulate(kTable->begin(), kTable->end(), 0)/kTable->size();
    delete kTable;
    return av;
}
double HyperGraphManager::calculateAverageK(const std::vector<int>& kTable)
{
    return (double) std::accumulate(kTable.begin(), kTable.end(), 0)/kTable.size();
}
std::vector<int>* HyperGraphManager::calculateKTable(const IncidencyMatrix& hyperGraph)
{
    auto k=new std::vector<int>(hyperGraph.getNumberOfVertexes());
    for(int i=0;i<hyperGraph.getNumberOfVertexes();i++)
    {
        for(int j=0;j<hyperGraph.getNumberOfHyperEdgess();j++)
        {
            (*k)[i]+=hyperGraph.getConnection(j,i);
        }
    }

    return k;
}
std::vector<int>* HyperGraphManager::generateKTable(const std::function<int()>& kDistribution,const int size)
{
    auto kTable=new std::vector<int>(size);
    std::for_each(kTable->begin(),kTable->end(),[&](auto & k){k=kDistribution();});
    return kTable;
}
std::vector<int>* HyperGraphManager::calculatePTable(const IncidencyMatrix &hyperGraph)
{
    auto pTable=new std::vector<int>(hyperGraph.getNumberOfHyperEdgess());
    for(int i=0;i<hyperGraph.getNumberOfHyperEdgess();i++)
    {
        for(int j=0;j<hyperGraph.getNumberOfVertexes();j++)
        {
            (*pTable)[i]+=hyperGraph.getConnection(i,j);
        }
    }
    return pTable;
}
double HyperGraphManager::calculateAverageP(const IncidencyMatrix& hyperGraph)
{
    auto pTable=calculatePTable(hyperGraph);
    double av=(double) std::accumulate(pTable->begin(), pTable->end(), 0)/pTable->size();
    delete pTable;
    return av;
}
double HyperGraphManager::calculateAverageP(const std::vector<int>& pTable)
{
    return (double) std::accumulate(pTable.begin(), pTable.end(), 0)/pTable.size();
}
std::vector<int>* HyperGraphManager::generatePTable(const std::function<int()>& pDistribution,const int size)
{
    auto pTable= new std::vector<int>(size);
    std::for_each(pTable->begin(),pTable->end(),[&](auto & p){p=pDistribution();});
    return pTable;
}
