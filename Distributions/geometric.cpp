#include "geometric.h"

#include<boost/math/distributions/geometric.hpp>



Geometric::Geometric(double parameter) : Distribution (), m_Geometric(parameter)
{

}


int Geometric::operator()()
{
    return m_Geometric(m_RandomNumberEngine);
}
std::vector<double> Geometric::GetTheoretical(int N,double parameter)
{
    boost::math::geometric_distribution<> posTheoretical(parameter);
    std::vector<double> prob ;
    prob.reserve(N);
    for(int k=0; k<N ;++k)
    {
        prob.emplace_back(boost::math::pdf(posTheoretical,k));
    }
    return prob;
}
std::vector<double> Geometric::GetTheoretical(int N)
{
    return Geometric::GetTheoretical(N,m_Geometric.p());
}
