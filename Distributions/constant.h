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

    int operator() ();

    virtual std::vector<double> GetTheoretical(int N);
    virtual double GetAverage();



protected:
    const int m_Value;
private:

};

#endif // CONSTANT_H
