#ifndef HYPERGRAPHFABRIC_H
#define HYPERGRAPHFABRIC_H
#include "HGStruct/hypergraph.h"
#include "Matrix/incidencymatrix.h"
#include <functional>
/**
 *  @author   Adam Szczepanski
 *  @date 10.05.2017
 *  @brief Fabric class fo HyperGraph
 *  This calss is for generating variouse Hypergraphs
 *
*/
class HyperGraphFabric {
public:
  HyperGraphFabric();

  // static HyperGraph* createHyperGraph(int numberOfVertexes );
  static HyperGraph *createTestHyperGraph(const int numberOfVertexes);
  static IncidencyMatrix *
  createTestIncidencyMatrix(const int numberOfVertexes,
                            const int numberOfHyperEdges);
  static IncidencyMatrix *
  createTest1IncidencyMatrix(const int numberOfVertexes,
                             const int degreeOFHyperEdge,
                             const std::function<int()> &kDistribution);
  static IncidencyMatrix *
  createRandomIncidencyMatrix(const int numberOfVertexes,
                              const int degreeOFHyperEdge,
                              const std::vector<int> &kTable);
  static IncidencyMatrix *createFullHypergraph(const int numberOfVertexes,
                                               const int degreeOFHyperEdge,
                                               const std::vector<int> &kTable);

protected:
private:
};

#endif // HYPERGRAPHFABRIC_H
