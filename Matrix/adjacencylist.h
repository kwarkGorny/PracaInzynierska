#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include <vector>
#include<set>
class AdjacencyList {
public:
  explicit AdjacencyList(const int quantityOfVertecies=0);

   void addVerticies(const int quantity = 1);
   void removeVertex(const int id);

   void addHyperEdges(const int quantity = 1);
   void removeHyperegde(const int pos);

   void addVertexToHyperedge(const int hyperedge, const int vertex);
   void removeVertexFromHyperedge(const int hyperedge, const int vertex);

  // int checkConnection(const )
   inline int getConnection(const int hyperedge, const int vertex) const{
       return adjacencylist[hyperedge].find(vertex)!=std::end(adjacencylist[hyperedge]);
   }
   inline int size()const{return adjacencylist.size();}
   inline const auto &getAdjacencyList() const { return adjacencylist; }
   inline auto &getAdjacencyList() { return adjacencylist; }
   inline const auto &getNumberOfVertices() const { return numberOfVertecies; }

protected:
private:
  int numberOfVertecies{0};
  std::vector<std::set<int>> adjacencylist{};
};

#endif // ADJACENCYLIST_H
