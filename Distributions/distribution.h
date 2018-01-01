#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H
#include<random>

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Distribution interface for random engine
*/


enum  DISTRIBUTION{
    CONST,
    UNIFORM,
    POISSON,
    GEOMETRIC,
    POWERLAW,
};


class Distribution
{
public:
    Distribution();
    virtual ~Distribution(){}

    virtual int operator ()() =0;

    virtual std::vector<double> GetTheoretical(int N) =0;

    virtual double GetAverage()=0;

protected:
private:

};

#endif // DISTRIBUTION_H
