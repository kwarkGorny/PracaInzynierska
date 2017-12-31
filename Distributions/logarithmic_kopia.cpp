#include "logarithmic.h"

#include<boost/math/distributions/poisson.hpp>

#include"Patterns/RandomSystem.h"


Logarithmic::Logarithmic(double average) : Distribution () , m_Poisson(average)
{

}


int Logarithmic::operator()()
{
    return m_Poisson(RANDOMSYSTEM.GetRandomEngine());
}
std::vector<double> Logarithmic::GetTheoretical(int N,double lambda)
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
std::vector<double> Logarithmic::GetTheoretical(int N)
{
    return Poisson::GetTheoretical(N,m_Poisson.mean());
}
double Logarithmic::GetAverage()
{
    return m_Poisson.mean();
}
