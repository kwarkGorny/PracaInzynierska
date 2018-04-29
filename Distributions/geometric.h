#ifndef GEOMETRIC_H
#define GEOMETRIC_H
#include"distribution.h"

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Geometric Distribution
*/


class Geometric : public Distribution
{
public:
    Geometric(double parameter);
    virtual~Geometric(){}

    int operator() () noexcept;

    static std::vector<double> GetTheoretical(int N,double parameter) noexcept;
    virtual std::vector<double> GetTheoretical(int N)const noexcept;

    virtual double GetAverage()const noexcept;
    virtual double GetMedian()const noexcept;
    virtual double GetStandDev()const noexcept;

    virtual bool IsValid()const noexcept;


protected:
    std::geometric_distribution<int> m_Geometric;
private:
};

#endif // GEOMETRIC_H
