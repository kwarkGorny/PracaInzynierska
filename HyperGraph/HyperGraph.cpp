#include "HyperGraph.h"
#include<algorithm>
HyperGraph::HyperGraph(int quantityOfVertecies) : m_NumberOfVertecies{quantityOfVertecies},m_HyperedgeList{}
{

}

void HyperGraph::AddVerticies(const int quantity)
{
    if(quantity>0)
    {
        m_NumberOfVertecies+=quantity;
    }
}

void HyperGraph::RemoveVertex(const int id)
{
    --m_NumberOfVertecies;
    std::for_each(m_HyperedgeList.begin(),m_HyperedgeList.end(),[&](auto&& hyperedge){hyperedge.erase(id);});
}

void HyperGraph::AddHyperEdge()
{
    m_HyperedgeList.emplace_back();
}

int HyperGraph::GetConnection(const int hyperedge, const int vertex) const
{
    return m_HyperedgeList[hyperedge].find(vertex)!=std::end(m_HyperedgeList[hyperedge]);
}

void HyperGraph::RemoveHyperegde(const int pos)
{
    if(pos>0)
    {
        m_HyperedgeList.erase(m_HyperedgeList.begin()+pos);
    }
}

bool HyperGraph::AddVertexToHyperedge(const int hyperedge, const int vertex)
{
   return m_HyperedgeList[hyperedge].insert(vertex).second;
}

void HyperGraph::RemoveVertexFromHyperedge(const int hyperedge, const int vertex)
{
    m_HyperedgeList[hyperedge].erase(vertex);
}

void HyperGraph::Reset()
{
    m_NumberOfVertecies =0;
    m_HyperedgeList.clear();
}
