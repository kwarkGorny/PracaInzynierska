#include"incidencymatrixtests.h"
#include<random>
#include<functional>

int IncidencyMatrixTest1(int argc, char *argv[])
{

    std::default_random_engine e(3);//valgrind dont recognise (std::random_device())()

    std::poisson_distribution<int> poisson(3.1);
      // std::uniform_int_distribution<int> kDistribution(1,6);
    //std::function<int()>kDistribution=std::bind(poisson,e);

   // IncidencyMatrix* hypergraph=HyperGraphFabric::createRandomIncidencyMatrix(100,5,kDistribution);

    //hypergraph->print();

   // delete hypergraph;

    return 1;
}
