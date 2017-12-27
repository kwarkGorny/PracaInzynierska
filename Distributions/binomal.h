#ifndef BINOMAL_H
#define BINOMAL_H
#include"distribution.h"

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Binomal Distribution
*/

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
