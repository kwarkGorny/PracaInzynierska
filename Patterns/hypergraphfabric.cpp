#include "hypergraphfabric.h"
#include<random>
#include<functional>
#include<algorithm>
#include<iostream>
#include<chrono>
#include"Patterns/hypergraphmanager.h"

HyperGraphFabric::HyperGraphFabric()
{
}
HyperGraph* HyperGraphFabric::createTestHyperGraph(const int numberOfVertexes)
{
    auto graph= new HyperGraph(numberOfVertexes);

    graph->createHyperEdge(5);

    for(auto& hyperedge:graph->getHyperEdges())
    {
        hyperedge.addVertex(graph->getVertex(0));
        hyperedge.addVertex(graph->getVertex(1));
        hyperedge.addVertex(graph->getVertex(2));
        hyperedge.removeVertex(graph->getVertex(2));
    }

    return  graph;
}

IncidencyMatrix* HyperGraphFabric::createTestIncidencyMatrix(const int numberOfVertexes,const int numberOfHyperEdges)
{
    auto matrix =new IncidencyMatrix(numberOfVertexes);

    std::default_random_engine e((std::random_device())());
    std::uniform_int_distribution<int> d(0,1);

    matrix->createHyperEdges(numberOfHyperEdges);
    for(auto  &hyperedge:matrix->getIncidencyMatrix())
    {
        for(auto &vertex:hyperedge)
        {
            vertex=d(e);
        }
    }
    return matrix;
}

IncidencyMatrix* HyperGraphFabric::createTest1IncidencyMatrix(const int numberOfVertexes, const int degreeOFHyperEdge, const std::function<int()>& kDistribution)
{
    auto graph=new IncidencyMatrix(numberOfVertexes);

    std::vector<int> kTable(numberOfVertexes);
    std::for_each(kTable.begin(),kTable.end(),[&](auto & k){k=kDistribution();});

   // std::for_each(kTable.begin(),kTable.end(),[&](auto & k){std::cout<<k<<std::endl;});

    for(int i=0;i<numberOfVertexes;i++)
    {

        while(kTable[i]>0)
        {

            int degree=1;
            std::vector<int> hyperedge(numberOfVertexes);
            --kTable[i];
            hyperedge[i]=1;
            for(int j=0;j<numberOfVertexes;j++)
            {
                if(degree==degreeOFHyperEdge)
                {
                    break;
                }
                if(i==j)
                {
                    continue;
                }
                if(kTable[j]>0)
                {
                    --kTable[j];
                    hyperedge[j]=1;
                    ++degree;
                }
            }
            graph->addHyperEdge(hyperedge);
        }

    }
    return graph;
}

IncidencyMatrix* HyperGraphFabric::createRandomIncidencyMatrix(const int numberOfVertexes,const int degreeOFHyperEdge,const std::vector<int>& kTable)
{


    auto graph = new IncidencyMatrix(numberOfVertexes);

    std::vector<int> kT{kTable};

    std::minstd_rand e((std::random_device())());

    int hyperedgeTries=0;
    bool succeed=false;
    for(int i=0;i<numberOfVertexes;++i)
    {
        std::uniform_int_distribution<int> randomvertex(i,numberOfVertexes-1);
        int maxNumberOfTries=numberOfVertexes-i;
        while(kT[i]>0)
        {
            graph->createHyperEdges();
            --kT[i];
            graph->getIncidencyMatrix().back()[i]=1;


            for(int j=1;j<degreeOFHyperEdge;++j)//i od jednego bo liczymy tez siebie
            {
               succeed=false;
               hyperedgeTries=0;
               while(!succeed)
               {
                    ++hyperedgeTries;
                    int index=randomvertex(e);
                    if(graph->getIncidencyMatrix().back()[index]==0)
                    {
                        if(kT[index]>0)
                        {
                            --kT[index];
                            graph->getIncidencyMatrix().back()[index]=1;
                            succeed=true;
                        }
                    }
                    //daje lepsze wyniki od stalych prob 5
                    if(hyperedgeTries>maxNumberOfTries)
                    {
                        succeed=true;
                    }
               }

            }

        }
    }
    return graph;
}

IncidencyMatrix* HyperGraphFabric::createFullHypergraph(const int numberOfVertexes,const int degreeOFHyperEdge,const std::vector<int>& kTable)
{
    auto graph = new IncidencyMatrix(numberOfVertexes);

    std::vector<int> kT{kTable};


    for(int i=0;i<numberOfVertexes;++i)
    {
        while(kT[i]>0)
        {
            --kT[i];
            graph->createHyperEdges();
            graph->getIncidencyMatrix().back()[i]=1;

        }
    }
    return graph;
}
