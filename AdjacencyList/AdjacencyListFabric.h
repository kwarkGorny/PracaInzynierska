#ifndef ADJACENCYLISTFABRIC_H
#define ADJACENCYLISTFABRIC_H
#include"AdjacencyList/AdjacencyList.h"
#include "Distributions/distribution.h"
#include "AdjacencyList//AdjacencyListManager.h"
#include<vector>

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Fabric for AdjacencyList
*/


class AdjacencyListFabric
{
public:
    //  static AdjacencyList*
    //  createRandomAdjacencyList(const int numberOfVertexes,
    //                              const int degreeOFHyperEdge,
    //                              const std::vector<int> &kTable);

      static AdjacencyList CreateRandomAdjacencyList(int numberOfVertices,Distribution &VertexDistribution,Distribution &HyperEdgeDistribution);

      static AdjacencyList CreateRandomAdjacencyList(std::vector<int> const& theoreticalKTable,Distribution &HyperEdgeDistribution);

protected:
private:
};

#endif // ADJACENCYLISTFABRIC_H
