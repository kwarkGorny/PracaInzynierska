#include"incidencymatrixtests.h"

int IncidencyMatrixTest1(int argc, char *argv[])
{
    IncidencyMatrix* hypergraph=HyperGraphFabric::createTestIncidencyMatrix(6,6);

    hypergraph->print();

    delete hypergraph;

    return 1;
}
