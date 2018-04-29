#include "powerlaw.h"
#include "Distributions/uniform.h"
#include <cmath>
PowerLaw::PowerLaw(int rangeStart, double distributionPower) : Distribution() , m_RangeStart(rangeStart), m_DistributionPower(distributionPower)
{
}

int PowerLaw::operator() () noexcept
{
    return PowerLaw::Variate( m_RangeStart,m_DistributionPower);
}

std::vector<double> PowerLaw::GetTheoretical(int N,int rangeStart, double distributionPower)noexcept
{
    std::vector<double> prob ;
    prob.reserve(N);
    const double powerMinusOne = distributionPower -1;
    const double distrConst = powerMinusOne * std::pow(rangeStart,powerMinusOne);
    for(int k=0; k<=N ;++k)
    {
        prob.emplace_back(distrConst * std::pow(k,-distributionPower));
    }
    return prob;
}

std::vector<double> PowerLaw::GetTheoretical(int N)const noexcept
{
    return PowerLaw::GetTheoretical(N,m_RangeStart,m_DistributionPower);
}

double PowerLaw::GetAverage()const noexcept
{
    return 0;
}
double PowerLaw::GetMedian()const noexcept
{
    return 0;
}
double PowerLaw::GetStandDev()const noexcept
{
    return 0;
}
double PowerLaw::Variate(int rangeStart, double distributionPower)noexcept
{
    return rangeStart * std::pow((1 - Uniform::GetReal(0,1)),-1/(distributionPower-1));
}

bool PowerLaw::IsValid()const noexcept
{
    return true;
}
