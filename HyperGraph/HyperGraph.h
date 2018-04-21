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
   explicit HyperGraph(int quantityOfVertecies=0)noexcept;
   HyperGraph(HyperGraph&&)noexcept = default;
   HyperGraph(HyperGraph const&) = default;
   HyperGraph& operator=(HyperGraph&& )noexcept = default;
   HyperGraph& operator=(HyperGraph const& ) = default;

   void AddVerticies(const int quantity = 1)noexcept;
   void RemoveVertex(const int id)noexcept;

   inline void AddHyperEdge()noexcept;
   inline void AddHyperEdge(HyperEdge&& hyperEdge)noexcept;
   inline void AddHyperEdge(HyperEdge const& hyperEdge)noexcept;
   void RemoveHyperegde(const int pos)noexcept;

   inline void Reserve(const int N)noexcept;

   bool AddVertexToHyperedge(const int hyperedge, const int vertex)noexcept;
   void RemoveVertexFromHyperedge(const int hyperedge, const int vertex)noexcept;

   int GetConnection(const int hyperedge, const int vertex) const noexcept;

   inline HyperEdge const& GetHyperEdge ( const int index )const noexcept;
   inline HyperEdge& GetHyperEdge(const int index)noexcept;

   inline HyperEdge const& begin()const noexcept;
   inline HyperEdge& begin() noexcept;

   inline HyperEdge const& end()const noexcept;
   inline HyperEdge& end() noexcept;


   inline auto size()const noexcept;
   inline int GetNumberOfVertices() const noexcept;

   inline HyperEdgeList const& GetHyperEdgeList() const noexcept;
   inline HyperEdgeList & GetHyperEdgeList() noexcept;

   void Reset() noexcept;

protected:
private:
  int m_NumberOfVertecies = 0;
  HyperEdgeList m_HyperedgeList = {};
};


void HyperGraph::AddHyperEdge(HyperEdge&& hyperEdge)noexcept
{
    m_HyperedgeList.emplace_back(std::move(hyperEdge));
}
void HyperGraph::AddHyperEdge(HyperEdge const& hyperEdge)noexcept
{
    m_HyperedgeList.emplace_back(hyperEdge);
}
HyperEdge const& HyperGraph::GetHyperEdge ( const int index )const noexcept
{
    return m_HyperedgeList[index];
}
HyperEdge& HyperGraph::GetHyperEdge(const int index)noexcept
{
    return m_HyperedgeList[index];
}
HyperEdge const& HyperGraph::begin()const noexcept
{
    return m_HyperedgeList[0];
}
HyperEdge& HyperGraph::begin() noexcept
{
    return m_HyperedgeList[0];
}
HyperEdge const& HyperGraph::end()const noexcept
{
    return m_HyperedgeList.back();
}
HyperEdge& HyperGraph::end() noexcept
{
    return m_HyperedgeList.back();
}
auto HyperGraph::size()const noexcept
{
    return m_HyperedgeList.size();
}
int HyperGraph::GetNumberOfVertices() const noexcept
{
    return m_NumberOfVertecies;
}
HyperEdgeList const& HyperGraph::GetHyperEdgeList() const noexcept
{
    return m_HyperedgeList;
}
HyperEdgeList & HyperGraph::GetHyperEdgeList() noexcept
{
    return m_HyperedgeList;
}
void HyperGraph::Reserve(const int N)noexcept
{
    m_HyperedgeList.reserve(N);
}

#endif // ADJACENCYLIST_H
