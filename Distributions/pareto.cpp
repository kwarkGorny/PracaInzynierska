#include "pareto.h"

Pareto::Pareto(int scale, int shape): Distribution()
{

}
std::vector<double> Pareto::GetTheoretical(int N,double scale,double shape)
{
    boost::math::pareto_distribution<> paretoTheoretical(scale,shape);
    std::vector<double> prob ;
    prob.reserve(N);
    for(int k=1; k<=N ;++k)
    {
        prob.emplace_back(boost::math::pdf(paretoTheoretical,k));
    }
    return prob;
}

std::vector<double> Pareto::GetTheoretical(int N)
{

}
int Pareto::operator()()
{
    return 0;
}
double Pareto::GetAverage()
{
   // boost::math::paretoTheoretical<> posTheoretical(m_Uniform.min(),m_Uniform.max());
   // return boost::math::mean(posTheoretical);
    return 0;
}
