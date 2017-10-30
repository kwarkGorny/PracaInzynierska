#ifndef BINOMAL_H
#define BINOMAL_H
#include"distribution.h"

class Binomal :public Distribution
{
public:
    Binomal();
    virtual~Binomal(){}

     int operator() ();

protected:
    std::binomial_distribution<int> m_Binomal;
private:


};

#endif // BINOMAL_H
