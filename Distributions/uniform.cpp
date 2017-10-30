#include "uniform.h"

#include<boost/math/distributions/uniform.hpp>


Uniform::Uniform(int start,int end): Distribution(),m_Uniform(start,end)
{
}
int Uniform::operator()()
{
    return  m_Uniform(m_RandomNumberEngine);
}
int Uniform::get(const int min ,const int max)
{
    std::uniform_int_distribution<int> uniform(min,max);
    return uniform(m_RandomNumberEngine);
}
std::vector<double> Uniform::GetTheoretical(int N,double min,double max)
{
    boost::math::uniform_distribution<> posTheoretical(min,max);
    std::vector<double> prob ;
    prob.reserve(N);
    for(int k=0; k<N ;++k)
    {
        prob.emplace_back(boost::math::pdf(posTheoretical,k));
    }
    return prob;
}
std::vector<double> Uniform::GetTheoretical(int N)
{
    return Uniform::GetTheoretical(N,m_Uniform.min(),m_Uniform.max());
}
