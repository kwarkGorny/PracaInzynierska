#ifndef HYPERGRAPHMANAGER_H
#define HYPERGRAPHMANAGER_H
#include"HGStruct/hypergraph.h"
#include"Matrix/incidencymatrix.h"
/**
 * @author   Adam Szczepanski
 * @date 10.05.2017
 *  @brief Manager class fo HyperGraph
 *  This class is for changing HaperGraph from 1 representation to other
 *
*/
class HyperGraphManager
{
public:
    HyperGraphManager();
    //TODO : implementthis two metods
    //static HyperGraph& IncidencyMatrixToHyperGraph(IncidencyMatrix& matrix);
    //static IncidencyMatrix& HyperGraphToIncidencyMatrix(HyperGraph& hypergraph);

    static double calculateK(IncidencyMatrix& hyperGraph);
protected:
private:

};

#endif // HYPERGRAPHMANAGER_H
