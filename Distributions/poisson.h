#ifndef POISSON_H
#define POISSON_H
#include"distribution.h"




class Poisson : public Distribution
{
public:
    Poisson(double average);
    virtual~Poisson(){}

    int operator() () ;

    static std::vector<double> GetTheoretical(int N,double lambda);
    virtual std::vector<double> GetTheoretical(int N);



protected:
    std::poisson_distribution<int> m_Poisson;
private:
};

#endif // POISSON_H
