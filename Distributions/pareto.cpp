#include "pareto.h"

#include"Patterns/RandomSystem.h"
#include <iostream>
#include <boost/random/uniform_real_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/math/distributions/complement.hpp>

#include <time.h>

Pareto::Pareto(int scale, double shape): Distribution() ,m_Scale(scale),m_Shape(shape),  m_Pareto(scale,shape)

{

}
std::vector<double> Pareto::GetTheoretical(int N,double scale,double shape)
{
    boost::mt19937 rg;
    rg.seed(time(NULL));
    boost::random::uniform_real_distribution<> uniformReal(0,1.0);
    boost::variate_generator<boost::mt19937&,boost::random::uniform_real_distribution<> > generator(rg,uniformReal);
    boost::math::pareto_distribution<> paretoTheoretical(scale,shape);

    std::vector<double> prob ;
    prob.reserve(N);
    for(int k=1; k<=N ;++k)
    {
        prob.emplace_back(boost::math::cdf(paretoTheoretical,generator()));
    }
    return prob;
}

std::vector<double> Pareto::GetTheoretical(int N)
{
    boost::mt19937 rg;
    rg.seed(time(NULL));
    boost::random::uniform_real_distribution<> uniformReal(0,1.0);
    boost::variate_generator<boost::mt19937&,boost::random::uniform_real_distribution<> > generator(rg,uniformReal);

    std::vector<double> prob;
    prob.reserve(N);
    for(int i=0;i<N;++i)
    {
        prob.emplace_back(boost::math::cdf(m_Pareto,generator()));
    }
    return prob;
}
int Pareto::operator()()
{
    boost::random::uniform_real_distribution<> uniformReal(0,1.0);
    boost::variate_generator<std::mt19937&,boost::random::uniform_real_distribution<> > generator(RANDOMSYSTEM.GetRandomEngine(),uniformReal);
    const double prob = boost::math::cdf(m_Pareto,generator());
    return prob;
}
double Pareto::GetAverage()
{
    return boost::math::mean(m_Pareto);

}
