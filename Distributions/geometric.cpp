#include "geometric.h"

#include<boost/math/distributions/geometric.hpp>

#include"Patterns/RandomSystem.h"

Geometric::Geometric(double parameter) : Distribution (), m_Geometric(parameter)
{

}

int Geometric::operator()()noexcept
{
    return m_Geometric(RANDOMSYSTEM.GetRandomEngine());
}

std::vector<double> Geometric::GetTheoretical(int N,double parameter)noexcept
{
    boost::math::geometric_distribution<> posTheoretical(parameter);
    std::vector<double> prob ;
    prob.reserve(N);
    for(int k=0; k<=N ;++k)
    {
        prob.emplace_back(boost::math::pdf(posTheoretical,k));
    }
    return prob;
}

std::vector<double> Geometric::GetTheoretical(int N)const noexcept
{
    return Geometric::GetTheoretical(N,m_Geometric.p());
}

double Geometric::GetAverage()const noexcept
{
    boost::math::geometric_distribution<> posTheoretical(m_Geometric.p());
    return boost::math::mean(posTheoretical);
}
double Geometric::GetMedian()const noexcept
{
    boost::math::geometric_distribution<> posTheoretical(m_Geometric.p());
    return boost::math::median(posTheoretical);
}
double Geometric::GetStandDev()const noexcept
{
    boost::math::geometric_distribution<> posTheoretical(m_Geometric.p());
    return boost::math::standard_deviation(posTheoretical);
}

bool Geometric::IsValid()const noexcept
{
    return true;
}
