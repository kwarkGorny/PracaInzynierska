#ifndef POWERLAW_H
#define POWERLAW_H

#include "Distributions/distribution.h"

class PowerLaw : public Distribution
{
public:
    PowerLaw(int rangeStart, double distributionPower);
    virtual~PowerLaw(){}

    int operator() () noexcept;

    virtual std::vector<double> GetTheoretical(int N)const noexcept;

    virtual double GetAverage()const noexcept;
    virtual double GetMedian()const noexcept;
    virtual double GetStandDev()const noexcept;

    virtual bool IsValid()const noexcept;


    static std::vector<double> GetTheoretical(int N,int rangeStart, double distributionPower)noexcept;
    static double Variate(int rangeStart, double distributionPower)noexcept;

protected:
    int m_RangeStart;
    double m_DistributionPower;
private:
};



#endif // POWERLAW_H
