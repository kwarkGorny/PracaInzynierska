#ifndef ADJACENCYLISTFABRIC_H
#define ADJACENCYLISTFABRIC_H
#include"Matrix/adjacencylist.h"
#include <functional>
#include<random>

class AdjacencyListFabric
{
public:
    //  static AdjacencyList*
    //  createRandomAdjacencyList(const int numberOfVertexes,
    //                              const int degreeOFHyperEdge,
    //                              const std::vector<int> &kTable);

      static AdjacencyList*
      createRandomAdjacencyList(const int numberOfVertices,
                                const std::function<int()>& HyperEdgeDistribution,
                                const  std::function<int()>& VertexDistribution);
protected:
private:
};

#endif // ADJACENCYLISTFABRIC_H
