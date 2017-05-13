#include<fstream>
#include<string>
#include<iostream>
#include "incidencymatrix.h"

IncidencyMatrix::IncidencyMatrix(int numberOfVertexes)
{
    this->numberOfVertexes=numberOfVertexes;
}
void IncidencyMatrix::createVertexes(int numberOfVertexes)
{
    this->numberOfVertexes+=numberOfVertexes;
    for(auto& hyperedge : incidencyMatrix)
    {
        for(int i=0;i<numberOfVertexes;i++)
        {
            hyperedge.push_back(0);
        }
    }
}
void IncidencyMatrix::removeVertex(int position)
{
    for(auto& hyperedge : incidencyMatrix)
    {
        hyperedge.erase(hyperedge.begin()+position);
    }
    numberOfVertexes--;
}
void IncidencyMatrix::createHyperEdges(int numberOfHyperEdges)
{
    for(int i=0;i<numberOfHyperEdges;i++)
    {
        incidencyMatrix.push_back(std::vector<int>(numberOfVertexes));
    }
}
void IncidencyMatrix::addHyperEdge(const std::vector<int>& hyperedge)
{
    incidencyMatrix.push_back(hyperedge);
}
void IncidencyMatrix::removeHyperEdge(int position)
{
    incidencyMatrix.erase(incidencyMatrix.begin()+position);
}
void IncidencyMatrix::setConnection (int positionOfHyperEdge,int positionOfVertex,int value)
{
    if(positionOfHyperEdge<incidencyMatrix.size()&&positionOfHyperEdge>=0)
    {
        if(positionOfVertex<numberOfVertexes&&positionOfVertex>=0)
        {
            incidencyMatrix[positionOfHyperEdge][positionOfVertex]=value;
        }
    }
}
int IncidencyMatrix::getConnection (int positionOfHyperEdge,int positionOfVertex)
{
    if(positionOfHyperEdge<incidencyMatrix.size()&&positionOfHyperEdge>=0)
    {
        if(positionOfVertex<numberOfVertexes&&positionOfVertex>=0)
        {
            return incidencyMatrix[positionOfHyperEdge][positionOfVertex];
        }
    }
    return 0;
}

void IncidencyMatrix::tofile(std::string& nameWithPath)
{
    std::ofstream file(nameWithPath);
    file<<numberOfVertexes<<'\n';
    for(auto& hyperedge : incidencyMatrix)
    {
        for(int i=0;i<numberOfVertexes;i++)
        {
            if(hyperedge[i]!=0)
            file<<i;
        }
        file<<'\n';
    }
    file.flush();
    file.close();
}


void IncidencyMatrix::print()
{

    std::cout<<"Number of Vertexes : "<<numberOfVertexes<<'\n';
    for(auto& hyperedge : incidencyMatrix)
    {
        for(auto& vertex: hyperedge)
        {
            std::cout<<vertex;
        }
        std::cout<<'\n';
    }
    std::cout<<"Average k: "<<k<<std::endl;
}





















