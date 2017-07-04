#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include <vector>
class AdjacencyList {
public:
  explicit AdjacencyList(const int quantityOfVertecies);

  inline void addVerticies(const int quantity = 1);
  void removeVertex(const int pos);

  inline void addHyperegdes(const int quantity = 1);
  inline void removeHyperegde(const int pos);

  inline void addVertexToHyperedge(const int hyperedge, const int vertex);
  inline void removeVertexFromHyperedge(const int hyperedge, const int vertex);

  // int checkConnection(const )
  inline int getConnection(const int hyperedge, const int vertex) const;

  inline const auto &getAdjacencyList() const { return adjacencylist; }
  inline auto &getAdjacencyList() { return adjacencylist; }
  inline const auto &getNumberOfVertices() const { return numberOfVertecies; }

protected:
private:
  int numberOfVertecies{0};
  std::vector<std::vector<int>> adjacencylist{};
};

#endif // ADJACENCYLIST_H
