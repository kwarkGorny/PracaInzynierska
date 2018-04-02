#ifndef ADJACENCYLISTFABRIC_H
#define ADJACENCYLISTFABRIC_H
#include"HyperGraph/HyperGraph.h"
#include "Distributions/distribution.h"
#include "HyperGraph//HyperGraphManager.h"
#include<vector>

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Fabric for HyperGraph
*/


class HyperGraphFabric
{
public:


      static HyperGraph CreateRandomHyperGraph(int numberOfVertices,Distribution & VertexDistribution,Distribution & HyperEdgeDistribution);
      static HyperGraph CreateRandomHyperGraph(std::vector<int> const& theoreticalKTable,Distribution &HyperEdgeDistribution);

protected:
private:
};

#endif // ADJACENCYLISTFABRIC_H
