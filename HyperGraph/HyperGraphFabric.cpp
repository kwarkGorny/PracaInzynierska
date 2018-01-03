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
                int hyperedgeTries = 0;
                int vertexId;

                --kTable[i];

                HyperEdge hyperEdge = {i};

                int theoreticalDegreeOfHyperedge = HyperEdgeDistribution();

                if(theoreticalDegreeOfHyperedge > numberOfVertices)//for more clarity move to distribution
                {
                    theoreticalDegreeOfHyperedge = numberOfVertices;
                }

                while(static_cast<unsigned int>(theoreticalDegreeOfHyperedge) > hyperEdge.size())
                {
                    vertexId = Uniform::Get(i,lastVertexId);
                    if(kTable[vertexId] > 0)
                    {
                        if(hyperEdge.insert(vertexId).second)
                        {
                            --kTable[vertexId];
                        }
                    }
                    else if(hyperedgeTries>maxNumberOfTries)
                    {
                        if(hyperEdge.insert(vertexId).second)
                        {
                            --kTable[vertexId];
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        ++hyperedgeTries;
                    }
                }
                hypergraph.AddHyperEdge(std::move(hyperEdge));
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
