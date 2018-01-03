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


    virtual std::vector<double> GetTheoretical(int N);
    virtual bool IsValid()const;
    virtual double GetAverage();

    static std::vector<double> GetTheoretical(int N,double min,double max);
    static double GetReal(const double min ,const double max);
    static int Get(const int min ,const int max);

protected:
private:
    std::uniform_int_distribution<int> m_Uniform;


};

#endif // UNIFORM_H
