#include "hypergraphmanager.h"
#include <numeric>
#include <vector>
HyperGraphManager::HyperGraphManager() {}

double HyperGraphManager::calculateAverageK(const AdjacencyList &hyperGraph) {
  auto kTable = calculateKTable(hyperGraph);
  double av =  std::accumulate(kTable->begin(), kTable->end(), 0) / kTable->size();
  delete kTable;
  return av;
}

std::vector<int> *
HyperGraphManager::calculateKTable(const AdjacencyList &hyperGraph) {
  auto k = new std::vector<int>(hyperGraph.getNumberOfVertices());
  for(int i = 0; i < hyperGraph.size(); ++i)
  {
    for(auto vertex:  hyperGraph.getHyperEdge(i))
    {
        (*k)[vertex]+=1;
    }
  }
  return k;
}
std::unordered_map<int,int> *HyperGraphManager::calculateKHistogram(const AdjacencyList &hyperGraph)
{
    auto k = new std::unordered_map<int,int> ();
    auto kTable=HyperGraphManager::calculateKTable(hyperGraph);

    for(auto vertex:*kTable)
    {
        (*k)[vertex]+=1;
    }
    delete kTable;

    return k;
}






std::vector<int> *
HyperGraphManager::calculatePTable(const AdjacencyList &hyperGraph) {
  auto pTable = new std::vector<int>(hyperGraph.size());
  for(int i = 0; i < hyperGraph.size(); ++i)
  {
        (*pTable)[i]+=hyperGraph.getHyperEdge(i).size();
  }
  return pTable;
}
double HyperGraphManager::calculateAverageP(const AdjacencyList &hyperGraph) {
  auto pTable = calculatePTable(hyperGraph);
  double av = (double)std::accumulate(pTable->begin(), pTable->end(), 0) /
              pTable->size();
  delete pTable;
  return av;
}
std::unordered_map<int,int> *HyperGraphManager::calculatePHistogram(const AdjacencyList &hyperGraph)
{
    auto k = new std::unordered_map<int,int> ();
    auto kTable=HyperGraphManager::calculatePTable(hyperGraph);

    for(auto vertex:*kTable)
    {
        (*k)[vertex]+=1;
    }
    delete kTable;

    return k;
}
std::vector<int> *
HyperGraphManager::generateTable(const std::function<int()> &distribution,
                                  const int size) {
  auto kTable = new std::vector<int>();
  kTable->reserve(size);
  for(int i=0;i<size;++i) kTable->emplace_back(distribution());
  return kTable;
}
void HyperGraphManager::adjacenyListToFile(const AdjacencyList &hyperGraph , const std::string& nameOfFile)
{
    std::ofstream file (nameOfFile);
    file<<hyperGraph.getNumberOfVertices()<<'\n';
    file<<hyperGraph.size()<<'\n';
    for(auto const& hyperedge : hyperGraph.getAdjacencyList())
    {
        for(auto const& vertex:hyperedge)
        {
            file<<vertex<<" ";
        }
        file<<'\n';
    }
    file.flush();
    file.close();
}
std::map<std::set<int>,int>* HyperGraphManager::getHyperEdgeHistogram(const AdjacencyList& hyperGraph)
{
    std::map<std::set<int>,int>* hyperEdgeHistogram=new std::map<std::set<int>,int>();
    for(auto const& hyperEdge : hyperGraph.getAdjacencyList())
    {
        ++(*hyperEdgeHistogram)[hyperEdge];
    }
    return hyperEdgeHistogram;

}
