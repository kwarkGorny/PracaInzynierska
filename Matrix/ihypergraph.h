#ifndef IHYPERGRAPH_H
#define IHYPERGRAPH_H
#include<vector>

class IHyperGraph
{
public:
    IHyperGraph();
    virtual ~IHyperGraph()=default;

    virtual void addVerticies(const int quantity = 1) =0;
    virtual void removeVertex(const int id) =0;

    virtual void addHyperEdges(const int quantity = 1) =0;
    virtual void removeHyperEgde(const int pos) =0;

    virtual void addVertexToHyperEdge(const int hyperedge, const int vertex) =0;
    virtual void removeVertexFromHyperEdge(const int hyperedge, const int vertex) =0;

    virtual int getConnection(const int hyperedge, const int vertex) const =0;

    virtual int getNumberOfVertices() const =0;
    virtual int getNumberOfHyperEdges() const =0;

    virtual const std::vector<int>& getHyperEdge()const=0;
    virtual std::vector<int>& getHyperEdge()=0;\

    virtual const std::vector<std::vector<int>> &getHyperGraph() const =0 ;
    virtual std::vector<std::vector<int>>  &getHyperGraph() =0;

};

#endif // IHYPERGRAPH_H
