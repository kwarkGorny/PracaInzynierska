#ifndef PARETO_H
#define PARETO_H
#include"distribution.h"
#include<random>
#include <iostream>
#include <boost/random/uniform_real_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/math/distributions/pareto.hpp>
#include <time.h>

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Pareto Distribution
*/


class Pareto : public Distribution
{
public:
    Pareto(int scale, int shape);
    virtual~Pareto(){}

    int operator() () ;

    static std::vector<double> GetTheoretical(int N,double scale,double shape);
     std::vector<double> GetTheoretical(int N);
     virtual double GetAverage();



protected:
private:
};


#endif // PARETO_H
