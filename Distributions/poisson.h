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

    int operator() () noexcept;


    virtual std::vector<double> GetTheoretical(int N)const noexcept;
    virtual bool IsValid()const noexcept;
    virtual double GetAverage()const noexcept;
    virtual double GetMedian()const noexcept;
    virtual double GetStandDev()const noexcept;

    static std::vector<double> GetTheoretical(int N,double lambda) noexcept;
protected:
    std::poisson_distribution<int> m_Poisson;
private:
};

#endif // POISSON_H
