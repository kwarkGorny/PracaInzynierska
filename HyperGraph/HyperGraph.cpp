#include "HyperGraph.h"
#include<algorithm>
HyperGraph::HyperGraph(int quantityOfVertecies)noexcept : m_NumberOfVertecies{quantityOfVertecies},m_HyperedgeList{}
{

}

void HyperGraph::AddVerticies(const int quantity)noexcept
{
    if(quantity>0)
    {
        m_NumberOfVertecies+=quantity;
    }
}

void HyperGraph::RemoveVertex(const int id)noexcept
{
    --m_NumberOfVertecies;
    std::for_each(m_HyperedgeList.begin(),m_HyperedgeList.end(),[&](auto&& hyperedge){hyperedge.erase(id);});
}



int HyperGraph::GetConnection(const int hyperedge, const int vertex) const noexcept
{
    return m_HyperedgeList[hyperedge].find(vertex)!=std::end(m_HyperedgeList[hyperedge]);
}

void HyperGraph::RemoveHyperegde(const int pos)noexcept
{
    if(pos>0)
    {
        m_HyperedgeList.erase(m_HyperedgeList.begin()+pos);
    }
}

bool HyperGraph::AddVertexToHyperedge(const int hyperedge, const int vertex)noexcept
{
   return m_HyperedgeList[hyperedge].insert(vertex).second;
}

void HyperGraph::RemoveVertexFromHyperedge(const int hyperedge, const int vertex)noexcept
{
    m_HyperedgeList[hyperedge].erase(vertex);
}

void HyperGraph::Reset() noexcept
{
    m_NumberOfVertecies =0;
    m_HyperedgeList.clear();
}
