#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include <vector>
#include <utility>
#include<set>
class AdjacencyList
{
public:
  explicit AdjacencyList(const int quantityOfVertecies=0);

   void addVerticies(const int quantity = 1);
   void removeVertex(const int id);

   void addHyperEdges(const int quantity = 1);
   inline void addHyperEdge(std::set<int>&& hyperEdge){adjacencylist.emplace_back(std::move(hyperEdge));}
   void removeHyperegde(const int pos);

   void addVertexToHyperedge(const int hyperedge, const int vertex);
   void removeVertexFromHyperedge(const int hyperedge, const int vertex);

   inline int getConnection(const int hyperedge, const int vertex) const{
       return adjacencylist[hyperedge].find(vertex)!=std::end(adjacencylist[hyperedge]);
   }

   inline auto& getHyperEdge(const int index)const{return adjacencylist[index];}
   inline auto const& getLastHyperEdge()const{return adjacencylist.back();}
   inline auto& getLastHyperEdge(){return adjacencylist.back();}


   inline auto size()const{return adjacencylist.size();}
   inline auto const& getNumberOfVertices() const { return numberOfVertecies; }

   inline auto const& getAdjacencyList() const { return adjacencylist; }
   inline auto & getAdjacencyList() { return adjacencylist; }


protected:
private:
  int numberOfVertecies{0};
  std::vector<std::set<int>> adjacencylist{};
};

#endif // ADJACENCYLIST_H
