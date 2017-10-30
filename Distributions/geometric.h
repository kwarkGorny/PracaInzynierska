#ifndef GEOMETRIC_H
#define GEOMETRIC_H
#include"distribution.h"

class Geometric : public Distribution
{
public:
    Geometric(double parameter);
    virtual~Geometric(){}

    int operator() ();

    static std::vector<double> GetTheoretical(int N,double parameter);

    virtual std::vector<double> GetTheoretical(int N);

protected:
    std::geometric_distribution<int> m_Geometric;
private:
};

#endif // GEOMETRIC_H
