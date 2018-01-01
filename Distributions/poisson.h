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


    virtual std::vector<double> GetTheoretical(int N);
    virtual bool IsValid()const;
    virtual double GetAverage();

    static std::vector<double> GetTheoretical(int N,double lambda);
protected:
    std::poisson_distribution<int> m_Poisson;
private:
};

#endif // POISSON_H
