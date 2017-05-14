#include "vertex.h"
#include<iostream>
Vertex::Vertex(const int vertexID) : id{vertexID},degree{0}
{
}
Vertex& Vertex::operator=(const Vertex& vertex)
{
    degree=vertex.getDegree();
    return *this;
}
Vertex& Vertex::operator++()
{
    --(this->degree);
    return *this;
}
Vertex& Vertex::operator--()
{
    --(this->degree);
    return *this;
}

void Vertex::print()
{
    std::cout <<"Vertex number "<< getId()<<" : "<<getDegree()<<" "<< '\n';
}
