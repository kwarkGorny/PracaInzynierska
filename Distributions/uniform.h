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

    int operator ()() noexcept;


    virtual std::vector<double> GetTheoretical(int N)const noexcept;

    virtual double GetAverage()const noexcept;
    virtual double GetMedian()const noexcept;
    virtual double GetStandDev()const noexcept;

    virtual bool IsValid()const noexcept;

    int getN()const noexcept;
    static double GetProbability(double min,double max) noexcept;
    static std::vector<double> GetTheoretical(int N,double min,double max) noexcept;
    static double GetReal(const double min ,const double max) noexcept;
    static int Get(const int min ,const int max) noexcept;

protected:
private:

    std::uniform_int_distribution<int> m_Uniform;
    int m_Start;
    int m_End;

};

#endif // UNIFORM_H
