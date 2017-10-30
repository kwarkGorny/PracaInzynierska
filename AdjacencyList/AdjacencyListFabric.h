#ifndef ADJACENCYLISTFABRIC_H
#define ADJACENCYLISTFABRIC_H
#include"AdjacencyList/AdjacencyList.h"
#include "Distributions/distribution.h"

class AdjacencyListFabric
{
public:
    //  static AdjacencyList*
    //  createRandomAdjacencyList(const int numberOfVertexes,
    //                              const int degreeOFHyperEdge,
    //                              const std::vector<int> &kTable);

      static AdjacencyList CreateRandomAdjacencyList(int numberOfVertices,
                                                      Distribution &HyperEdgeDistribution,
                                                      Distribution &VertexDistribution);



protected:
private:
};

#endif // ADJACENCYLISTFABRIC_H
