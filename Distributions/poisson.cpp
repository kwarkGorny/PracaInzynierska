#include "poisson.h"

#include<boost/math/distributions/poisson.hpp>

#include"Patterns/RandomSystem.h"


Poisson::Poisson(double average) : Distribution () , m_Poisson(average)
{

}
int Poisson::operator()()
{
    return m_Poisson(RANDOMSYSTEM.GetRandomEngine());
}

std::vector<double> Poisson::GetTheoretical(int N,double lambda)
{
    boost::math::poisson_distribution<> posTheoretical(lambda);
    std::vector<double> prob ;
    prob.reserve(N);
    for(int k=0; k<=N ;++k)
    {
        prob.emplace_back(boost::math::pdf(posTheoretical,k));
    }
    return prob;
}

std::vector<double> Poisson::GetTheoretical(int N)
{
    return Poisson::GetTheoretical(N,m_Poisson.mean());
}

double Poisson::GetAverage()
{
    return m_Poisson.mean();
}

bool Poisson::IsValid()const
{
    return true;
}
