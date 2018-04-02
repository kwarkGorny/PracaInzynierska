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
   HyperGraph(HyperGraph&&) = default; // forces a move constructor anyway
   HyperGraph(HyperGraph const&) = default; // forces a move constructor anyway
   HyperGraph& operator=(HyperGraph&& ) = default;
   HyperGraph& operator=(HyperGraph const& ) = default;

   void AddVerticies(const int quantity = 1);
   void RemoveVertex(const int id);

   void AddHyperEdge();
   inline void AddHyperEdge(HyperEdge&& hyperEdge) {m_HyperedgeList.emplace_back(std::move(hyperEdge));}
   inline void AddHyperEdge(HyperEdge const& hyperEdge) {m_HyperedgeList.emplace_back(hyperEdge);}

   inline void Reserve(const int N){m_HyperedgeList.reserve(N);}
   void RemoveHyperegde(const int pos);

   bool AddVertexToHyperedge(const int hyperedge, const int vertex);
   void RemoveVertexFromHyperedge(const int hyperedge, const int vertex);

   int GetConnection(const int hyperedge, const int vertex) const;

   inline HyperEdge const& GetHyperEdge ( const int index )const{return m_HyperedgeList[index];}
   inline HyperEdge& GetHyperEdge(const int index){return m_HyperedgeList[index];}

   inline HyperEdge const& begin()const {return m_HyperedgeList[0];}
   inline HyperEdge& begin() {return m_HyperedgeList[0];}

   inline HyperEdge const& end()const {return m_HyperedgeList.back();}
   inline HyperEdge& end() {return m_HyperedgeList.back();}


   inline auto size()const {return m_HyperedgeList.size();}
   inline int GetNumberOfVertices() const {return m_NumberOfVertecies; }

   inline HyperEdgeList const& GetHyperGraph() const {return m_HyperedgeList; }
   inline HyperEdgeList & GetHyperGraph() {return m_HyperedgeList; }

   void Reset();

protected:
private:
  int m_NumberOfVertecies = 0;
  HyperEdgeList m_HyperedgeList = {};
};

#endif // ADJACENCYLIST_H
