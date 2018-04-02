#include "powerlaw.h"
#include "Distributions/uniform.h"
#include <cmath>
PowerLaw::PowerLaw(int rangeStart, double distributionPower) : Distribution() , m_RangeStart(rangeStart), m_DistributionPower(distributionPower)
{
}

int PowerLaw::operator() ()
{
    return PowerLaw::Variate( m_RangeStart,m_DistributionPower);
}

std::vector<double> PowerLaw::GetTheoretical(int N,int rangeStart, double distributionPower)
{
    std::vector<double> prob ;
    prob.reserve(N);
    for(int k=0; k<=N ;++k)
    {
        //prob.emplace_back(PowerLaw::Variate( rangeStart,distributionPower));
    }
    return prob;
}

std::vector<double> PowerLaw::GetTheoretical(int N)
{
    return PowerLaw::GetTheoretical(N,m_RangeStart,m_DistributionPower);
}

double PowerLaw::GetAverage()
{
    return 0;
}

double PowerLaw::Variate(int rangeStart, double distributionPower)
{
    return rangeStart * std::pow((1 - Uniform::GetReal(0,1)),-1/(distributionPower-1));
}

bool PowerLaw::IsValid()const
{
    return true;
}
