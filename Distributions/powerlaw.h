#ifndef POWERLAW_H
#define POWERLAW_H

#include "Distributions/distribution.h"

class PowerLaw : public Distribution
{
public:
    PowerLaw(int rangeStart, double distributionPower);
    virtual~PowerLaw(){}

    int operator() ();

    virtual std::vector<double> GetTheoretical(int N);
    virtual double GetAverage();

    static std::vector<double> GetTheoretical(int N,int rangeStart, double distributionPower);

    static double Variate(int rangeStart, double distributionPower);

protected:
    int m_RangeStart;
    double m_DistributionPower;
private:
};



#endif // POWERLAW_H
