#ifndef HYPERGRAPHMANAGER_H
#define HYPERGRAPHMANAGER_H

#include"HyperGraph/HyperGraph.h"

#include <vector>
#include<map>
#include<set>


/**
 * @author   Adam Szczepanski
 * @date 10.05.2017
 * @brief Manager class fo HyperGraph
 *
 *
*/


class HyperGraphManager
{
public:
  static std::vector<int> CalculatePTable(const HyperEdgeList& hyperGraph);
  static std::vector<int> CalculateKTable(const HyperGraph& hyperGraph);

  static void MakeLoops(HyperGraph &hyperGraph,int vertexId,int amount);

  static std::map<HyperEdge,int> CalculateHyperedgeDuplicates(const HyperEdgeList& hyperGraph);
  static void ShowHyperedgeDuplicates(const std::map<HyperEdge,int>& hyperGraphDuplicates);

  static std::vector<int> KTableFromFile(const std::string& nameOfFile);

  static void AdjacenyListToFile(const HyperGraph &hyperGraph , const std::string& nameOfFile);
  static HyperGraph AdjacenyListFromFile(const std::string& nameOfFile);

protected:
private:
    HyperGraphManager(){}
};

#endif // HYPERGRAPHMANAGER_H
