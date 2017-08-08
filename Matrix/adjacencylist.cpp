#include "adjacencylist.h"
#include<algorithm>
AdjacencyList::AdjacencyList(const int quantityOfVertecies)
    : numberOfVertecies{quantityOfVertecies} {}
void AdjacencyList::addVerticies(const int quantity)
{
    if(quantity>0){
    numberOfVertecies+=quantity;
    }
}
void AdjacencyList::removeVertex(const int id){
    numberOfVertecies--;
    std::for_each(adjacencylist.begin(),adjacencylist.end(),[&](auto&& hyperedge){hyperedge.erase(id);});
}
void AdjacencyList::addHyperEdges(const int quantity)
{
    if(quantity>0){
        adjacencylist.emplace_back();
    }

}
void AdjacencyList::removeHyperegde(const int pos){
    if(pos>0){
        adjacencylist.erase(adjacencylist.begin()+pos);
    }
}
void AdjacencyList::addVertexToHyperedge(const int hyperedge, const int vertex)
{
    adjacencylist[hyperedge].insert(vertex);
}
void AdjacencyList::removeVertexFromHyperedge(const int hyperedge, const int vertex)
{
    adjacencylist[hyperedge].erase(vertex);
}
