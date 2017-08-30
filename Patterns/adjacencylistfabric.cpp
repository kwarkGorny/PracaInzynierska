#include "adjacencylistfabric.h"
#include<iostream>

AdjacencyList* AdjacencyListFabric::createRandomAdjacencyList(const int numberOfVertices,
                                                            const std::function<int()>& HyperEdgeDistribution,
                                                            const std::function<int()>& VertexDistribution)
{
    auto graph = new AdjacencyList(numberOfVertices);
   // graph->getAdjacencyList().reserve(1.68*numberOfVertices);
    std::vector<int> kTable;
    kTable.reserve(numberOfVertices);
    for(int i=0;i<numberOfVertices;++i) kTable.emplace_back(VertexDistribution());

    std::minstd_rand e((std::random_device())());

    for (int i = 0; i < numberOfVertices; ++i)
    {
      if(kTable[i]>0)
      {
          const int maxNumberOfTries = numberOfVertices - i;

          std::uniform_int_distribution<int> randomvertex(i, numberOfVertices - 1);

          while (kTable[i] > 0)
          {

              --kTable[i];
              graph->addHyperEdge({i});
              const int degreeOfHyperedge = HyperEdgeDistribution();

              int hyperedgeTries = 0;
              while(graph->getLastHyperEdge().size()< static_cast<unsigned int>(degreeOfHyperedge) )
              {
                  int vertex=randomvertex(e);
                  if(kTable[vertex] > 0)
                  {
                      //if vertex wasnt already added to hyperedge
                     if(graph->getLastHyperEdge().insert(vertex).second!=false)
                     {
                        --kTable[vertex];
                     }
                  }
                  else if(hyperedgeTries>maxNumberOfTries)
                  {
                      //if vertex wasnt already added to hyperedge
                      if(graph->getLastHyperEdge().insert(vertex).second!=false)
                      {
                         --kTable[vertex];
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
    return graph;
}

