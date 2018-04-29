#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H
#include<random>

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Distribution interface for random engine
*/


enum  DISTRIBUTION
{
    CONST,
    UNIFORM,
    POISSON,
    GEOMETRIC,
    POWERLAW,
};

class Distribution
{
public:
    Distribution(){}
    virtual ~Distribution(){}

    virtual int operator ()() noexcept=0;

    virtual std::vector<double> GetTheoretical(int N)const noexcept=0;

    virtual double GetAverage()const noexcept=0;
    virtual double GetMedian()const noexcept=0;
    virtual double GetStandDev()const noexcept=0;

    virtual bool IsValid()const noexcept{return false;}


protected:
private:

};

#endif // DISTRIBUTION_H
