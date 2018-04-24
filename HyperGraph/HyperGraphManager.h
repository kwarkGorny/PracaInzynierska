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
  static std::vector<int> CalculatePTable ( HyperEdgeList const& hyperGraph) noexcept;
  static std::vector<int> CalculateKTable ( HyperGraph const& hyperGraph )noexcept;

  static void MakeLoops ( HyperGraph &hyperGraph, int vertexId, int amount )noexcept;

  static std::map<HyperEdge,int> CalculateHyperedgeDuplicates ( HyperEdgeList const& hyperGraph )noexcept;
  static void ShowHyperedgeDuplicates ( std::map<HyperEdge,int> const& hyperGraphDuplicates )noexcept;

  static std::vector<int> KTableFromFile ( std::string const& nameOfFile)noexcept;

  static void HyperGraphToFile ( HyperGraph const& hyperGraph, std::string const& nameOfFile )noexcept;
  static HyperGraph HyperGraphFromFile ( std::string const& nameOfFile)noexcept;

protected:
private:
    HyperGraphManager(){}
};

#endif // HYPERGRAPHMANAGER_H
