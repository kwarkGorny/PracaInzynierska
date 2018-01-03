#include "HyperGraphFabric.h"

#include"Distributions/uniform.h"
#include "Patterns/Statistics.h"
#include<algorithm>
#include<iostream>
HyperGraph HyperGraphFabric::CreateRandomHyperGraph(std::vector<int> const& theoreticalKTable,Distribution &HyperEdgeDistribution)
{
    const int numberOfVertices =theoreticalKTable.size();
    const int lastVertexId = numberOfVertices-1;

    HyperGraph hypergraph(numberOfVertices);
    std::vector<int> kTable = theoreticalKTable;

    for (int i = 0; i < lastVertexId ; ++i)
    {
      if(kTable[i]>0)
      {
          const int maxNumberOfTries = numberOfVertices - i;
          while (kTable[i] > 0)
          {

              --kTable[i];

              hypergraph.AddHyperEdge({i});

              int degreeOfHyperedge = HyperEdgeDistribution();
              if(degreeOfHyperedge > numberOfVertices)
              {
                  degreeOfHyperedge = numberOfVertices;
              }
              int hyperedgeTries = 0;
              bool failed =false;
              int vertex;
              while(hypergraph.end().size() < static_cast<unsigned int>(degreeOfHyperedge) && failed == false )
              {
                  vertex=Uniform::get(i,lastVertexId);
                  if(kTable[vertex] > 0)
                  {
                     if(hypergraph.end().insert(vertex).second)
                     {
                        --kTable[vertex];
                     }
                  }
                  else if(hyperedgeTries>maxNumberOfTries)
                  {
                      if(hypergraph.end().insert(vertex).second)
                      {
                         --kTable[vertex];
                      }
                      else
                      {
                           failed = true;
                      }
                  }
                  else
                  {
                      ++hyperedgeTries;
                  }
              }
          }
      }
    }
    HyperGraphManager::MakeLoops(hypergraph,lastVertexId,kTable[lastVertexId]);//making loops for last vertex
    return hypergraph;
}

HyperGraph HyperGraphFabric::CreateRandomHyperGraph(int numberOfVertices,Distribution &VertexDistribution,Distribution &HyperEdgeDistribution)
{    
    return CreateRandomHyperGraph(Statistics::GenerateTable(numberOfVertices,VertexDistribution),HyperEdgeDistribution);
}