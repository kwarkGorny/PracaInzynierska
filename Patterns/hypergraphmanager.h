#ifndef HYPERGRAPHMANAGER_H
#define HYPERGRAPHMANAGER_H

#include"Matrix/adjacencylist.h"
#include"enums.h"

#include <algorithm>
#include <functional>
#include <vector>
#include <unordered_map>
#include<map>
#include<set>
#include <string>
#include<iostream>
#include<fstream>
/**
 * @author   Adam Szczepanski
 * @date 10.05.2017
 * @brief Manager class fo HyperGraph
 *
 *
*/


class HyperGraphManager {
public:
  HyperGraphManager();

  static double calculateAverageK(const AdjacencyList &hyperGraph);
  static std::vector<int> *calculateKTable(const AdjacencyList &hyperGraph);
  static std::unordered_map<int,int> *calculateKHistogram(const AdjacencyList &hyperGraph);

  static double calculateAverageP(const AdjacencyList &hyperGraph);
  static std::vector<int> *calculatePTable(const AdjacencyList &hyperGraph);
  static std::unordered_map<int,int> *calculatePHistogram(const AdjacencyList &hyperGraph);


  static std::vector<int> *generateTable(const std::function<int()>& distribution, const int size);

  static std::map<std::set<int>,int>* getHyperEdgeHistogram(const AdjacencyList& hyperGraph);
  // TODO : implementthis two metods
  // static HyperGraph& IncidencyMatrixToHyperGraph(IncidencyMatrix& matrix);
  // static IncidencyMatrix& HyperGraphToIncidencyMatrix(HyperGraph&
  // hypergraph);

  static void adjacenyListToFile(const AdjacencyList &hyperGraph , const std::string& nameOfFile);

protected:
private:
};

#endif // HYPERGRAPHMANAGER_H
