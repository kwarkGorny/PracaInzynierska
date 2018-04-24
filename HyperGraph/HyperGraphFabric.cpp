#include "HyperGraphFabric.h"

#include"Distributions/uniform.h"
#include "Patterns/Statistics.h"

#include<algorithm>
HyperGraph HyperGraphFabric::CreateRandomHyperGraph(std::vector<int> const& theoreticalKTable,Distribution &HyperEdgeDistribution)
{
    const int numberOfVertices =theoreticalKTable.size();
    const int lastVertexId = numberOfVertices-1;

    HyperGraph hypergraph(numberOfVertices);
    std::vector<int> kTable = theoreticalKTable;

    for (int i = 0; i < lastVertexId ; ++i)
    {
        const int maxNumberOfTries = numberOfVertices - i;
        while (kTable[i] > 0)
        {
            --kTable[i];

            HyperEdge hyperEdge = {i};
            int theoreticalDegreeOfHyperedge = HyperEdgeDistribution();
            if(theoreticalDegreeOfHyperedge > numberOfVertices)
            {
                theoreticalDegreeOfHyperedge = numberOfVertices;
            }
            int hyperedgeTries = 0;
            while(theoreticalDegreeOfHyperedge > static_cast<int>(hyperEdge.size()))
            {
                const int randomVertex = Uniform::Get(i,lastVertexId);
                if(kTable[randomVertex])
                {
                    if(hyperEdge.insert(randomVertex).second)
                    {
                        --kTable[randomVertex];
                    }
                }
                else if(hyperedgeTries>maxNumberOfTries)
                {
                    if(hyperEdge.insert(randomVertex).second)
                    {
                        --kTable[randomVertex];
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
    HyperGraphManager::MakeLoops(hypergraph,lastVertexId,kTable[lastVertexId]);//making loops for last vertex
    return hypergraph;
}

HyperGraph HyperGraphFabric::CreateRandomHyperGraph(int numberOfVertices,Distribution &VertexDistribution,Distribution &HyperEdgeDistribution)
{    
    return CreateRandomHyperGraph(Statistics::GenerateTable(numberOfVertices,VertexDistribution),HyperEdgeDistribution);
}
