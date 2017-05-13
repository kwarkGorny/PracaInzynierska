#ifndef HYPERGRAPHFABRIC_H
#define HYPERGRAPHFABRIC_H
#include"HGStruct/hypergraph.h"
#include"Matrix/incidencymatrix.h"
/**
 *  @author   Adam Szczepanski
 *  @date 10.05.2017
 *  @brief Fabric class fo HyperGraph
 *  This calss is for generating variouse Hypergraphs
 *
*/
class HyperGraphFabric
{
public:
    HyperGraphFabric();

    //static HyperGraph* createHyperGraph(int numberOfVertexes );
    static HyperGraph* createTestHyperGraph(int numberOfVertexes);
    static IncidencyMatrix* createTestIncidencyMatrix(int numberOfVertexes);

protected:
private:

};

#endif // HYPERGRAPHFABRIC_H
