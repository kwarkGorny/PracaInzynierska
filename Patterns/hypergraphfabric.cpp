#include "hypergraphfabric.h"
#include<random>
HyperGraphFabric::HyperGraphFabric()
{

}
HyperGraph* HyperGraphFabric::createTestHyperGraph(int numberOfVertexes)
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
IncidencyMatrix* HyperGraphFabric::createTestIncidencyMatrix(int numberOfVertexes)
{
    std::default_random_engine e((std::random_device())());
    std::uniform_int_distribution<int> d(0,1);
    IncidencyMatrix* matrix =new IncidencyMatrix(numberOfVertexes);
    matrix->createHyperEdges(5);
    matrix->setK(0);
    for(auto&hyperedge:matrix->getIncidencyMatrix())
    {
        for(auto &vertex:hyperedge)
        {
            vertex=d(e);
            matrix->setK(matrix->getK()+vertex);
        }
    }
    matrix->setK(matrix->getK()/5);
    return matrix;
}
