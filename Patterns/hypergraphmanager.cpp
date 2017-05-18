#include "hypergraphmanager.h"

HyperGraphManager::HyperGraphManager()
{
}

double HyperGraphManager::calculateK(IncidencyMatrix& hyperGraph)
{
    double k=0.0;
    for(const auto& hyperedge : hyperGraph.getIncidencyMatrix())
    {
        for(const auto& vertex: hyperedge)
        {
            k+=vertex;
        }
    }
    return k;
}
