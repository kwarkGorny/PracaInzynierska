#ifndef HYPERGRAPHMANAGER_H
#define HYPERGRAPHMANAGER_H

#include"AdjacencyList/AdjacencyList.h"

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


class AdjacencyListManager {
public:
  AdjacencyListManager();

  static std::vector<int> CalculatePTable(const std::vector<std::set<int>>& hyperGraph);
  static std::vector<int> CalculateKTable(const AdjacencyList& hyperGraph);


  static std::map<std::set<int>,int> CalculateHyperedgeDuplicates(const std::vector<std::set<int>>& hyperGraph);
  static void AdjacenyListToFile(const AdjacencyList &hyperGraph , const std::string& nameOfFile);

protected:
private:
};

#endif // HYPERGRAPHMANAGER_H
