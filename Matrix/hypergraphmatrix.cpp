#include "hypergraphmatrix.h"

#include <fstream>
#include <string>

HyperGraphMatrix::HyperGraphMatrix(const int numberOfVertexes) {
  for (int i = 0; i < numberOfVertexes; i++) {
    matrix.push_back(std::vector<int>());
  }
}
void HyperGraphMatrix::createVertexes(const int numberOfVertexes) {
  for (int i = 0; i < numberOfVertexes; i++) {
    matrix.push_back(std::vector<int>());
  }
}
void HyperGraphMatrix::removeVertex(const int position) {
  matrix.erase(matrix.begin() + position);
}
void HyperGraphMatrix::createHyperEdges(const int numberOfHyperEdges) {
  for (auto &vertex : matrix) {
    for (int i = 0; i < numberOfHyperEdges; i++) {
      vertex.push_back(0);
    }
  }
}
// void HyperGraphMatrix::addHyperEdge(const std::vector<int>& hyperedge)
//{
//    for(auto& vertex:matrix)
//    {
//        vertex.push_back(hyperedge);
//    }
//}
void HyperGraphMatrix::removeHyperEdge(const int position) {
  for (auto &vertex : matrix) {
    vertex.erase(vertex.begin() + position);
  }
}
void HyperGraphMatrix::setConnection(const int positionOfVertex,
                                     const int positionOfHyperEdge,
                                     const int value) {
  if (positionOfVertex < matrix.size() && positionOfVertex >= 0) {
    if (positionOfHyperEdge < matrix[positionOfVertex].size() &&
        positionOfHyperEdge >= 0) {
      matrix[positionOfVertex][positionOfHyperEdge] = value;
    }
  }
}
int HyperGraphMatrix::getConnection(const int positionOfVertex,
                                    const int positionOfHyperEdge) const {
  if (positionOfVertex < matrix.size() && positionOfVertex >= 0) {
    if (positionOfHyperEdge < matrix[positionOfVertex].size() &&
        positionOfHyperEdge >= 0) {
      return matrix[positionOfVertex][positionOfHyperEdge];
    }
  }
  return 0;
}
void HyperGraphMatrix::tofile(const std::string &nameWithPath) const {
  std::ofstream file(nameWithPath);
  file << matrix.size() << '\n';
  for (const auto &vertex : matrix) {
    for (int i = 0, max = vertex.size(); i < max; i++) {
      if (vertex[i] != 0) {
        file << i;
      }
    }
    file << '\n';
  }
  file.flush();
  file.close();
}
void HyperGraphMatrix::print() const {}
