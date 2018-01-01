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

    int operator() ();


    virtual std::vector<double> GetTheoretical(int N);

    virtual bool IsValid()const;
    virtual double GetAverage();


    static std::vector<double> GetTheoretical(int N,double parameter);

protected:
    std::geometric_distribution<int> m_Geometric;
private:
};

#endif // GEOMETRIC_H
