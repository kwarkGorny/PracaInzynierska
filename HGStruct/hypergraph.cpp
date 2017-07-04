#include "hypergraph.h"
#include <algorithm>
HyperGraph::HyperGraph(const int numberOfVertexes) {
  for (int i = 0; i < numberOfVertexes; i++) {
    Vertexes.push_back(Vertex(validVertexId));
    validVertexId++;
  }
}

void HyperGraph::createVertex(const int numberOfVertexes) {
  for (int i = 0; i < numberOfVertexes; i++) {
    Vertexes.push_back(Vertex(validVertexId));
    validVertexId++;
  }
}

void HyperGraph::removeVertex(const int vertexId) {
  Vertexes.erase(std::remove_if(Vertexes.begin(), Vertexes.end(),
                                [&](auto const &vertex) {
                                  return vertex.getId() == vertexId;
                                }),
                 Vertexes.end());
}

bool HyperGraph::isContainingVertex(const int vertexId) const {
  const auto iter =
      std::find_if(Vertexes.begin(), Vertexes.end(), [&](auto const &vertex) {
        return vertex.getId() == vertexId;
      });
  return (iter != Vertexes.end());
}

void HyperGraph::createHyperEdge(const int numberOfHyperEdges) {
  for (int i = 0; i < numberOfHyperEdges; ++i) {
    HyperEdges.push_back(HyperEdge(validHyperEdgeId));
    ++validHyperEdgeId;
  }
}

void HyperGraph::removeHyperEdge(const int hyperedgeID) {
  HyperEdges.erase(std::remove_if(
      HyperEdges.begin(), HyperEdges.end(),
      [&](auto const &hyperedge) { return hyperedge.getId() == hyperedgeID; }));
}

void HyperGraph::addHyperEdge(const std::vector<Vertex *> &listOfVertexes) {
  HyperEdges.push_back(HyperEdge(validHyperEdgeId, listOfVertexes));
  validHyperEdgeId++;
}

bool HyperGraph::isContainingHyperEdge(const int hyperedgeID) const {
  auto iter = std::find_if(
      HyperEdges.begin(), HyperEdges.end(),
      [&](auto const &hyperEdge) { return hyperEdge.getId() == hyperedgeID; });
  return (iter != HyperEdges.end());
}

void HyperGraph::addVertexToHyperEdge(HyperEdge *hyperedge, Vertex *vertex) {
  if (hyperedge->isContainingVertex(vertex->getId()) == false) {
    hyperedge->addVertex(vertex);
  }
}

void HyperGraph::print() const {

  std::cout << "Number of Vertexes : " << Vertexes.size() << '\n';
  std::cout << "Vertexes id :  degree  " << '\n';
  for (auto const &v1 : Vertexes) {
    v1.print();
  }
  std::cout << "Number of Edges : " << HyperEdges.size() << " :ID of vertexes"
            << '\n';
  for (auto const &e1 : HyperEdges) {
    std::cout << "Edge number " << e1.getId() << " : ";
    e1.print();
  }
}
