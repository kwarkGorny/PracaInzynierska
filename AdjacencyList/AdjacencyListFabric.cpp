#include "AdjacencyListFabric.h"

#include"Distributions/uniform.h"
#include "Patterns/Statistics.h"

AdjacencyList AdjacencyListFabric::CreateRandomAdjacencyList(int numberOfVertices,
                                                              Distribution &HyperEdgeDistribution,
                                                              Distribution &VertexDistribution)
{
    AdjacencyList graph(numberOfVertices);

    auto kTable = Statistics::GenerateTable(numberOfVertices,VertexDistribution);

    int last = numberOfVertices-1;
    for (int i = 0; i < last ; ++i)
    {
      if(kTable[i]>0)
      {
          const int maxNumberOfTries = numberOfVertices - i;
          while (kTable[i] > 0)
          {

              --kTable[i];

              graph.AddHyperEdge({i});

              int degreeOfHyperedge = HyperEdgeDistribution();
              if(degreeOfHyperedge > numberOfVertices)
              {
                  degreeOfHyperedge = numberOfVertices;
              }
              int hyperedgeTries = 0;
              bool failed =false;
              int vertex;
              while(graph.end().size() < static_cast<unsigned int>(degreeOfHyperedge) && failed == false )
              {
                  vertex=Uniform::get(i,numberOfVertices);
                  if(kTable[vertex] > 0)
                  {
                     if(graph.end().insert(vertex).second)
                     {
                        --kTable[vertex];
                     }
                  }
                  else if(hyperedgeTries>maxNumberOfTries)
                  {
                      if(graph.end().insert(vertex).second)
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
    while(kTable[last]>0)
    {
        --kTable[last];
        graph.AddHyperEdge({last});
    }

    return graph;
}
