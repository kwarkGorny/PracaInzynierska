#include "hypergraphfabric.h"
#include "Patterns/hypergraphmanager.h"
#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <random>

HyperGraphFabric::HyperGraphFabric() {}
HyperGraph *HyperGraphFabric::createTestHyperGraph(const int numberOfVertexes) {
  auto graph = new HyperGraph(numberOfVertexes);

  graph->createHyperEdge(5);

  for (auto &hyperedge : graph->getHyperEdges()) {
    hyperedge.addVertex(graph->getVertex(0));
    hyperedge.addVertex(graph->getVertex(1));
    hyperedge.addVertex(graph->getVertex(2));
    hyperedge.removeVertex(graph->getVertex(2));
  }

  return graph;
}

IncidencyMatrix *
HyperGraphFabric::createTestIncidencyMatrix(const int numberOfVertexes,
                                            const int numberOfHyperEdges) {
  auto matrix = new IncidencyMatrix(numberOfVertexes);

  std::default_random_engine e((std::random_device())());
  std::uniform_int_distribution<int> d(0, 1);

  matrix->createHyperEdges(numberOfHyperEdges);
  for (auto &hyperedge : matrix->getIncidencyMatrix()) {
    for (auto &vertex : hyperedge) {
      vertex = d(e);
    }
  }
  return matrix;
}

IncidencyMatrix *
HyperGraphFabric::createRandomIncidencyMatrix(const int numberOfVertexes,
                                              const int degreeOFHyperEdge,
                                              const std::vector<int> &kTable) {

  auto graph = new IncidencyMatrix(numberOfVertexes);

  std::vector<int> kT{kTable};

  std::minstd_rand e((std::random_device())());

  int hyperedgeTries = 0;
  bool succeed = false;
  for (int i = 0; i < numberOfVertexes; ++i) {
    std::uniform_int_distribution<int> randomvertex(i, numberOfVertexes - 1);
    int maxNumberOfTries = numberOfVertexes - i;
    while (kT[i] > 0) {
      graph->createHyperEdges();
      --kT[i];
      graph->getIncidencyMatrix().back()[i] = 1;

      for (int j = 1; j < degreeOFHyperEdge;
           ++j) // i od jednego bo liczymy tez siebie
      {
        succeed = false;
        hyperedgeTries = 0;
        while (!succeed) {
          ++hyperedgeTries;
          int index = randomvertex(e);
          if (graph->getIncidencyMatrix().back()[index] == 0) {
            if (kT[index] > 0) {
              --kT[index];
              graph->getIncidencyMatrix().back()[index] = 1;
              succeed = true;
            }
          }
          // daje lepsze wyniki od stalych prob 5
          if (hyperedgeTries > maxNumberOfTries) {
            succeed = true;
          }
        }
      }
    }
  }
  return graph;
}


IncidencyMatrix *
HyperGraphFabric::createFullHypergraph(const int numberOfVertexes,
                                       const int degreeOFHyperEdge,
                                       const std::vector<int> &kTable) {
  auto graph = new IncidencyMatrix(numberOfVertexes);

  std::vector<int> kT{kTable};

  for (int i = 0; i < numberOfVertexes; ++i) {
    while (kT[i] > 0) {
      --kT[i];
      graph->createHyperEdges();
      graph->getIncidencyMatrix().back()[i] = 1;
    }
  }
  return graph;
}
