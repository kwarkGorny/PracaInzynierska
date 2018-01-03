#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include <vector>
#include<set>

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief HyperGraph implementation
*/


typedef std::set<int> HyperEdge;
typedef std::vector<HyperEdge> HyperEdgeList;

class HyperGraph
{
public:
  explicit HyperGraph(int quantityOfVertecies=0);

   void AddVerticies(const int quantity = 1);
   void RemoveVertex(const int id);

   void AddHyperEdge();
   inline void AddHyperEdge(HyperEdge&& hyperEdge) {m_Hyperedgelist.emplace_back(std::move(hyperEdge));}
   inline void AddHyperEdge(HyperEdge const& hyperEdge) {m_Hyperedgelist.emplace_back(hyperEdge);}

   inline void Reserve(const int N){m_Hyperedgelist.reserve(N);}
   void RemoveHyperegde(const int pos);

   bool AddVertexToHyperedge(const int hyperedge, const int vertex);
   void RemoveVertexFromHyperedge(const int hyperedge, const int vertex);

   inline int GetConnection(const int hyperedge, const int vertex) const
   {
       return m_Hyperedgelist[hyperedge].find(vertex)!=std::end(m_Hyperedgelist[hyperedge]);
   }

   inline HyperEdge const& GetHyperEdge(const int index)const{return m_Hyperedgelist[index];}
   inline HyperEdge& GetHyperEdge(const int index){return m_Hyperedgelist[index];}

   inline HyperEdge const& begin()const {return m_Hyperedgelist[0];}
   inline HyperEdge& begin() {return m_Hyperedgelist[0];}

   inline HyperEdge const& end()const {return m_Hyperedgelist.back();}
   inline HyperEdge& end() {return m_Hyperedgelist.back();}


   inline auto size()const {return m_Hyperedgelist.size();}
   inline int GetNumberOfVertices() const {return m_NumberOfVertecies; }

   inline HyperEdgeList const& GetHyperGraph() const {return m_Hyperedgelist; }
   inline HyperEdgeList & GetHyperGraph() {return m_Hyperedgelist; }

   void Reset();

protected:
private:
  int m_NumberOfVertecies{0};
  HyperEdgeList m_Hyperedgelist{};
};

#endif // ADJACENCYLIST_H
