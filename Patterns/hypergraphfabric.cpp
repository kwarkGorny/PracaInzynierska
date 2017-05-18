#include "hypergraphfabric.h"
#include<random>
HyperGraphFabric::HyperGraphFabric()
{
}
HyperGraph* HyperGraphFabric::createTestHyperGraph(const int numberOfVertexes)
{
    HyperGraph* graph= new HyperGraph(numberOfVertexes);

    graph->createHyperEdge(5);

    for(auto& hyperedge:graph->getHyperEdges())
    {
        hyperedge.addVertex(graph->getVertex(0));
        hyperedge.addVertex(graph->getVertex(1));
        hyperedge.addVertex(graph->getVertex(2));
        hyperedge.removeVertex(graph->getVertex(2));
    }

    return  graph;
}
IncidencyMatrix* HyperGraphFabric::createTestIncidencyMatrix(const int numberOfVertexes,const int numberOfHyperEdges)
{
    IncidencyMatrix* matrix =new IncidencyMatrix(numberOfVertexes);

    std::default_random_engine e((std::random_device())());
    std::uniform_int_distribution<int> d(0,1);

    matrix->createHyperEdges(numberOfHyperEdges);
    for(auto  &hyperedge:matrix->getIncidencyMatrix())
    {
        for(auto &vertex:hyperedge)
        {
            vertex=d(e);
        }
    }
    return matrix;
}
