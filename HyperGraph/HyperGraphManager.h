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
  static std::vector<int> CalculatePTable ( HyperEdgeList const& hyperGraph) ;
  static std::vector<int> CalculateKTable ( HyperGraph const& hyperGraph );

  static void MakeLoops ( HyperGraph &hyperGraph, int vertexId, int amount );

  static std::map<HyperEdge,int> CalculateHyperedgeDuplicates ( HyperEdgeList const& hyperGraph );
  static void ShowHyperedgeDuplicates ( std::map<HyperEdge,int> const& hyperGraphDuplicates );

  static std::vector<int> KTableFromFile ( std::string const& nameOfFile);

  static void AdjacenyListToFile ( HyperGraph const& hyperGraph, std::string const& nameOfFile );
  static HyperGraph AdjacenyListFromFile ( std::string const& nameOfFile);

protected:
private:
    HyperGraphManager(){}
};

#endif // HYPERGRAPHMANAGER_H
