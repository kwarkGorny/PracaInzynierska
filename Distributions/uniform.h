#ifndef UNIFORM_H
#define UNIFORM_H
#include<random>
#include"distribution.h"

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Uniform Distribution
*/


class Uniform : public Distribution
{
public:
    Uniform(int start,int end);
    virtual ~Uniform(){}

    int operator ()() ;

    static int get(const int min ,const int max);
    static double getReal(const double min ,const double max);

    static std::vector<double> GetTheoretical(int N,double min,double max);

    virtual std::vector<double> GetTheoretical(int N);
    virtual double GetAverage();



protected:
private:
    std::uniform_int_distribution<int> m_Uniform;


};

#endif // UNIFORM_H
