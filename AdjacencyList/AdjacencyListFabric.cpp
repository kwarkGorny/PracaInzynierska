#include "AdjacencyListFabric.h"

#include"Distributions/uniform.h"
#include "Patterns/Statistics.h"
#include<algorithm>
#include<iostream>
AdjacencyList AdjacencyListFabric::CreateRandomAdjacencyList(int numberOfVertices,
                                                             std::vector<int>& kTable,
                                                             Distribution &HyperEdgeDistribution)
{
    AdjacencyList graph(numberOfVertices);
   // int estimatedNumberOfHyperedges =averageK*numberOfVertices/HyperEdgeDistribution.GetAverage();
   // std::cout<<"estimated number of hyperedges: "<<estimatedNumberOfHyperedges<<'\n';
   // graph.Reserve(estimatedNumberOfHyperedges);
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

AdjacencyList AdjacencyListFabric::CreateRandomAdjacencyList(int numberOfVertices,
                                                             Distribution &VertexDistribution,
                                                             Distribution &HyperEdgeDistribution)
{

    auto kTable = Statistics::GenerateTable(numberOfVertices,VertexDistribution);
    
    return CreateRandomAdjacencyList(numberOfVertices,kTable,HyperEdgeDistribution);
}
