#ifndef HYPERGRAPHMANAGER_H
#define HYPERGRAPHMANAGER_H

#include"AdjacencyList/AdjacencyList.h"

#include <vector>
#include<map>
#include<set>


/**
 * @author   Adam Szczepanski
 * @date 10.05.2017
 * @brief Manager class fo AdjacencyList
 *
 *
*/


class AdjacencyListManager
{
public:
  static std::vector<int> CalculatePTable(const std::vector<std::set<int>>& hyperGraph);
  static std::vector<int> CalculateKTable(const AdjacencyList& hyperGraph);

  static void MakeLoops(AdjacencyList &hyperGraph,int vertexId,int amount);

  static std::map<std::set<int>,int> CalculateHyperedgeDuplicates(const std::vector<std::set<int>>& hyperGraph);
  static void ShowHyperedgeDuplicates(const std::map<std::set<int>,int>& hyperGraphDuplicates);

  static std::vector<int> KTableFromFile(const std::string& nameOfFile);

  static void AdjacenyListToFile(const AdjacencyList &hyperGraph , const std::string& nameOfFile);
  static AdjacencyList AdjacenyListFromFile(const std::string& nameOfFile);

protected:
private:
    AdjacencyListManager(){}
};

#endif // HYPERGRAPHMANAGER_H
