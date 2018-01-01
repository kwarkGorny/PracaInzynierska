#include "AdjacencyList.h"
#include<algorithm>
AdjacencyList::AdjacencyList(int quantityOfVertecies) : m_NumberOfVertecies{quantityOfVertecies}
{

}

void AdjacencyList::AddVerticies(const int quantity)
{
    if(quantity>0)
    {
        m_NumberOfVertecies+=quantity;
    }
}

void AdjacencyList::RemoveVertex(const int id)
{
    --m_NumberOfVertecies;
    std::for_each(m_Adjacencylist.begin(),m_Adjacencylist.end(),[&](auto&& hyperedge){hyperedge.erase(id);});
}

void AdjacencyList::AddHyperEdge()
{
    m_Adjacencylist.emplace_back();
}

void AdjacencyList::RemoveHyperegde(const int pos)
{
    if(pos>0)
    {
        m_Adjacencylist.erase(m_Adjacencylist.begin()+pos);
    }
}

bool AdjacencyList::AddVertexToHyperedge(const int hyperedge, const int vertex)
{
   return m_Adjacencylist[hyperedge].insert(vertex).second;
}

void AdjacencyList::RemoveVertexFromHyperedge(const int hyperedge, const int vertex)
{
    m_Adjacencylist[hyperedge].erase(vertex);
}

void AdjacencyList::Reset()
{
    m_NumberOfVertecies =0;
    m_Adjacencylist.clear();
}
