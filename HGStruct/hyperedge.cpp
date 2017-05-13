#include "hyperedge.h"
#include"vertex.h"
#include<memory>
#include<algorithm>


HyperEdge::HyperEdge(int eID):id(eID)
{

}
HyperEdge::HyperEdge(int eID,std::vector<Vertex*>& vertexes):id(eID),connectedVerexes(std::move(vertexes))
{

}
HyperEdge& HyperEdge::operator=(const HyperEdge& hyperedge)
{
    connectedVerexes=hyperedge.getConnectedVerexes();
    return *this;
}
void HyperEdge::addVertex(Vertex* vertex)
{
    if(vertex!=nullptr)
    {
        connectedVerexes.push_back(vertex);
        ++*vertex;
    }
}
void HyperEdge::removeVertex(int vertexID )
{
    connectedVerexes.erase(std::remove_if(connectedVerexes.begin(),connectedVerexes.end(),
                                          [&](auto vertex){ if(vertex->getId()==vertexID){ --*vertex;return true;}return false;}),
                                            connectedVerexes.end());
}
void HyperEdge::removeVertex(Vertex*remove_vertex )
{
    connectedVerexes.erase(std::remove_if(connectedVerexes.begin(),connectedVerexes.end(),
                                          [&](auto vertex){ if(vertex==remove_vertex){ --*vertex;return true;}return false;}),
                                            connectedVerexes.end());
}
bool HyperEdge::isContainingVertex(int vertexID)const
{
    auto iter= std::find_if(connectedVerexes.begin(),connectedVerexes.end(),[&](auto vertex){ return vertex->getId()==vertexID;});
    return (iter!=connectedVerexes.end());
}

void HyperEdge::print(){
    for(auto& vertex:connectedVerexes){
        std::cout<< vertex->getId()<<" ";
    }
    std::cout<<'\n';
}
