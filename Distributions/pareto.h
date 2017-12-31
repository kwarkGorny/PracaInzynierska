#ifndef PARETO_H
#define PARETO_H
#include"distribution.h"
#include <boost/math/distributions/pareto.hpp>

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Pareto Distribution
*/


class Pareto : public Distribution
{
public:
    Pareto(int scale, double shape);
    virtual~Pareto(){}

    int operator() () ;

    static std::vector<double> GetTheoretical(int N,double scale,double shape);
     std::vector<double> GetTheoretical(int N);
     virtual double GetAverage();



protected:
private:
     int m_Scale;
     double m_Shape;
     boost::math::pareto_distribution<> m_Pareto;

};


#endif // PARETO_H
