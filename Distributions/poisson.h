#ifndef POISSON_H
#define POISSON_H
#include"distribution.h"

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Poisson Distribution
*/



class Poisson : public Distribution
{
public:
    Poisson(double average);
    virtual~Poisson(){}

    int operator() () ;

    static std::vector<double> GetTheoretical(int N,double lambda);
    virtual std::vector<double> GetTheoretical(int N);
    virtual double GetAverage();



protected:
    std::poisson_distribution<int> m_Poisson;
private:
};

#endif // POISSON_H
