#include "HyperGraph.h"
#include<algorithm>
HyperGraph::HyperGraph(int quantityOfVertecies) : m_NumberOfVertecies{quantityOfVertecies}
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
    std::for_each(m_Hyperedgelist.begin(),m_Hyperedgelist.end(),[&](auto&& hyperedge){hyperedge.erase(id);});
}

void HyperGraph::AddHyperEdge()
{
    m_Hyperedgelist.emplace_back();
}

void HyperGraph::RemoveHyperegde(const int pos)
{
    if(pos>0)
    {
        m_Hyperedgelist.erase(m_Hyperedgelist.begin()+pos);
    }
}

bool HyperGraph::AddVertexToHyperedge(const int hyperedge, const int vertex)
{
   return m_Hyperedgelist[hyperedge].insert(vertex).second;
}

void HyperGraph::RemoveVertexFromHyperedge(const int hyperedge, const int vertex)
{
    m_Hyperedgelist[hyperedge].erase(vertex);
}

void HyperGraph::Reset()
{
    m_NumberOfVertecies =0;
    m_Hyperedgelist.clear();
}
