#include "constant.h"

Constant::Constant(int value) :Distribution () , m_Value(value)
{
}

int Constant::operator()()noexcept
{
    return m_Value;
}

std::vector<double> Constant::GetTheoretical(int N)const noexcept
{
    std::vector<double> prob(N);
    prob[m_Value] = 1;
    return prob;
}

double Constant::GetAverage()const noexcept
{
    return m_Value;
}
double Constant::GetMedian()const noexcept
{
    return m_Value;
}
double Constant::GetStandDev()const noexcept
{
    return 0;
}

bool Constant::IsValid()const noexcept
{
    return true;
}
