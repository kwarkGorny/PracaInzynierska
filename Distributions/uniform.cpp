#include "uniform.h"

#include"Patterns/RandomSystem.h"

#include<boost/math/distributions/uniform.hpp>
#include<boost/random/uniform_int.hpp>

Uniform::Uniform(int start,int end): Distribution(),m_Uniform(start,end),m_Start(start),m_End(end)
{
}

int Uniform::operator()()noexcept
{
    return  m_Uniform(RANDOMSYSTEM.GetRandomEngine());
}

int Uniform::Get(const int min ,const int max)noexcept
{
    std::uniform_int_distribution<int> uniform(min,max);
    return uniform(RANDOMSYSTEM.GetRandomEngine());
}

double Uniform::GetReal(const double min ,const double max)noexcept
{
    std::uniform_real_distribution<double> uniform(min,max);
    return uniform(RANDOMSYSTEM.GetRandomEngine());
}

std::vector<double> Uniform::GetTheoretical(int N,double min,double max)noexcept
{
    std::vector<double> distr ;
    distr.reserve(N);
    const double prob= GetProbability(min,max);
    for(int k=0; k<=max ;++k)
    {
        if(k>=min && k<=max)
        {
            distr.emplace_back(prob);
        }
        else
        {
            distr.emplace_back(0);
        }
    }
    return distr;
}

std::vector<double> Uniform::GetTheoretical(int N)const noexcept
{
    return Uniform::GetTheoretical(N,m_Start,m_End);
}

double Uniform::GetAverage()const noexcept
{
    return (m_Start+m_End)/2.0;
}
double Uniform::GetMedian()const noexcept
{
    return (m_Start+m_End)/2.0;
}
double Uniform::GetStandDev()const noexcept
{
    const int N = getN();
    return sqrt((N*N-1)/12);
}
bool Uniform::IsValid()const noexcept
{
    return true;
}
double Uniform::GetProbability(double min,double max) noexcept
{
    return 1/(max - min+1);
}
int Uniform::getN()const noexcept
{
    return (m_End - m_Start+1);
}
