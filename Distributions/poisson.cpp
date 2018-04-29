#include "poisson.h"
#include<boost/math/distributions/poisson.hpp>
#include"Patterns/RandomSystem.h"


Poisson::Poisson(double average) : Distribution () , m_Poisson(average)
{
}
int Poisson::operator()()noexcept
{
    return m_Poisson(RANDOMSYSTEM.GetRandomEngine());
}

std::vector<double> Poisson::GetTheoretical(int N,double lambda)noexcept
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

std::vector<double> Poisson::GetTheoretical(int N)const noexcept
{
    return Poisson::GetTheoretical(N,m_Poisson.mean());
}

double Poisson::GetAverage()const noexcept
{
    return m_Poisson.mean();
}
double Poisson::GetMedian()const noexcept
{
    return m_Poisson.mean()+ 1/3.0 - 0.02/m_Poisson.mean(); //https://en.wikipedia.org/wiki/Poisson_distribution
}
double Poisson::GetStandDev()const noexcept
{
    return sqrt(m_Poisson.mean());
}
bool Poisson::IsValid()const noexcept
{
    return true;
}
