#ifndef CONSTANT_H
#define CONSTANT_H
#include"Distributions/distribution.h"

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Constant Distribution
*/


class Constant : public Distribution
{
public:
    Constant(int value);
    virtual ~Constant(){}

    int operator() () noexcept;

    virtual std::vector<double> GetTheoretical(int N)const noexcept;
    virtual double GetAverage()const noexcept;
    virtual double GetMedian()const noexcept;
    virtual double GetStandDev()const noexcept;

    virtual bool IsValid()const noexcept;



protected:
    const int m_Value;
private:

};

#endif // CONSTANT_H
