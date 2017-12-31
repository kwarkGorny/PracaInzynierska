#include "uniform.h"

#include"Patterns/RandomSystem.h"

#include<boost/math/distributions/uniform.hpp>


Uniform::Uniform(int start,int end): Distribution(),m_Uniform(start,end)
{
}
int Uniform::operator()()
{
    return  m_Uniform(RANDOMSYSTEM.GetRandomEngine());
}
int Uniform::get(const int min ,const int max)
{
    std::uniform_int_distribution<int> uniform(min,max);
    return uniform(RANDOMSYSTEM.GetRandomEngine());
}
double Uniform::getReal(const double min ,const double max)
{
    std::uniform_real_distribution<double> uniform(min,max);
    return uniform(RANDOMSYSTEM.GetRandomEngine());
}
std::vector<double> Uniform::GetTheoretical(int N,double min,double max)
{
    boost::math::uniform_distribution<> posTheoretical(min-1,max);//we want to min inclusive
    std::vector<double> prob ;
    prob.reserve(N+1);
    for(int k=0; k<=N ;++k)
    {
        prob.emplace_back(boost::math::pdf(posTheoretical,k));
    }
    return prob;
}
std::vector<double> Uniform::GetTheoretical(int N)
{
    return Uniform::GetTheoretical(N,m_Uniform.min(),m_Uniform.max());
}
double Uniform::GetAverage()
{
    boost::math::uniform_distribution<> posTheoretical(m_Uniform.min(),m_Uniform.max());
    return boost::math::mean(posTheoretical);
}
