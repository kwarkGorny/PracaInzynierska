#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H
#include<random>


enum  DISTRIBUTION{
    CONST,
    UNIFORM,
    POISSON,
    BINOMIAL,
    GEOMETRIC,
};


class Distribution
{
public:
    Distribution();
    virtual ~Distribution(){}

    virtual int operator ()() =0;


    virtual std::vector<double> GetTheoretical(int N) =0;

    static std::mt19937 m_RandomNumberEngine;

protected:
private:

};

#endif // DISTRIBUTION_H
