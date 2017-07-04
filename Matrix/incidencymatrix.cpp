#include "incidencymatrix.h"
#include <fstream>
#include <iostream>
#include <string>

IncidencyMatrix::IncidencyMatrix(const int numberOfVertexes) {
  this->numberOfVertexes = numberOfVertexes;
}

void IncidencyMatrix::createVertexes(const int numberOfVertexes) {
  this->numberOfVertexes += numberOfVertexes;
  for (auto &hyperedge : incidencyMatrix) {
    for (int i = 0; i < numberOfVertexes; ++i) {
      hyperedge.push_back(0);
    }
  }
}

void IncidencyMatrix::removeVertex(const int position) {
  for (auto &hyperedge : incidencyMatrix) {
    if (hyperedge.begin() + position < hyperedge.end()) {
      hyperedge.erase(hyperedge.begin() + position);
      --numberOfVertexes;
      return;
    }
  }
}

void IncidencyMatrix::createHyperEdges(const int numberOfHyperEdges) {
  for (int i = 0; i < numberOfHyperEdges; ++i) {
    incidencyMatrix.push_back(std::vector<int>(numberOfVertexes));
  }
}

void IncidencyMatrix::addHyperEdge(const std::vector<int> &hyperedge) {
  incidencyMatrix.push_back(hyperedge);
}

void IncidencyMatrix::removeHyperEdge(const int position) {
  if (position < incidencyMatrix.size() && position >= 0) {
    incidencyMatrix.erase(incidencyMatrix.begin() + position);
  }
}

void IncidencyMatrix::setConnection(const int positionOfHyperEdge,
                                    const int positionOfVertex,
                                    const int value) {
  if (positionOfHyperEdge < incidencyMatrix.size() &&
      positionOfHyperEdge >= 0) {
    if (positionOfVertex < numberOfVertexes && positionOfVertex >= 0) {
      incidencyMatrix[positionOfHyperEdge][positionOfVertex] = value;
    }
  }
}

int IncidencyMatrix::getConnection(const int positionOfHyperEdge,
                                   const int positionOfVertex) const {
  if (positionOfHyperEdge < incidencyMatrix.size() &&
      positionOfHyperEdge >= 0) {
    if (positionOfVertex < numberOfVertexes && positionOfVertex >= 0) {
      return incidencyMatrix[positionOfHyperEdge][positionOfVertex];
    }
  }
  return 0;
}

void IncidencyMatrix::tofile(const std::string &nameWithPath) const {
  std::ofstream file(nameWithPath);
  file << numberOfVertexes << '\n';
  for (auto const &hyperedge : incidencyMatrix) {
    for (int i = 0; i < numberOfVertexes; i++) {
      if (hyperedge[i] != 0) {
        file << i;
      }
    }
    file << '\n';
  }
  file.flush();
  file.close();
}

void IncidencyMatrix::print() const {

  std::cout << "Number of Vertexes : " << numberOfVertexes << '\n';
  for (auto const &hyperedge : incidencyMatrix) {
    for (auto const &vertex : hyperedge) {
      std::cout << vertex;
    }
    std::cout << '\n';
  }
  std::cout << std::endl;
}
