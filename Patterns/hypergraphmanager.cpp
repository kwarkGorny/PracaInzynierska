#include "hypergraphmanager.h"

HyperGraphManager::HyperGraphManager()
{
}
double HyperGraphManager::calculateK(IncidencyMatrix& hyperGraph)
{
    double k=0.0;
    for(auto& hyperedge:hyperGraph.getIncidencyMatrix())
    {
        for(auto& vertex: hyperedge)
        {
            k+=vertex;
        }
    }
    return k;
}
