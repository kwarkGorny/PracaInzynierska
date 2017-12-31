#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include <vector>
#include<set>

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief AdjacencyList implementation
*/


class AdjacencyList
{
public:
  explicit AdjacencyList(int quantityOfVertecies=0);

   void AddVerticies(const int quantity = 1);
   void RemoveVertex(const int id);

   void AddHyperEdge();
   inline void AddHyperEdge(std::set<int>&& hyperEdge) {m_Adjacencylist.emplace_back(std::move(hyperEdge));}
   inline void AddHyperEdge(std::set<int> const& hyperEdge) {m_Adjacencylist.emplace_back(hyperEdge);}

   inline void Reserve(const int N){m_Adjacencylist.reserve(N);}
   void RemoveHyperegde(const int pos);

   bool AddVertexToHyperedge(const int hyperedge, const int vertex);
   void RemoveVertexFromHyperedge(const int hyperedge, const int vertex);

   inline int GetConnection(const int hyperedge, const int vertex) const
   {
       return m_Adjacencylist[hyperedge].find(vertex)!=std::end(m_Adjacencylist[hyperedge]);
   }

   inline auto& GetHyperEdge(const int index)const {return m_Adjacencylist[index];}

   inline auto const& begin()const {return m_Adjacencylist[0];}
   inline auto& begin() {return m_Adjacencylist[0];}

   inline auto const& end()const {return m_Adjacencylist.back();}
   inline auto& end() {return m_Adjacencylist.back();}


   inline auto size()const {return m_Adjacencylist.size();}
   inline int GetNumberOfVertices() const {return m_NumberOfVertecies; }

   inline auto const& GetAdjacencyList() const {return m_Adjacencylist; }
   inline auto & GetAdjacencyList() {return m_Adjacencylist; }

   void Reset();

protected:
private:
  int m_NumberOfVertecies{0};
  std::vector<std::set<int>> m_Adjacencylist{};
};

#endif // ADJACENCYLIST_H
