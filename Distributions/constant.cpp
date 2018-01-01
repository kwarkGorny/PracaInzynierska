#include "constant.h"

Constant::Constant(int value) :Distribution () , m_Value(value)
{
}

int Constant::operator()()
{
    return m_Value;
}

std::vector<double> Constant::GetTheoretical(int N)
{
    std::vector<double> prob(N);
    prob[m_Value] = 1;

    return prob;
}

double Constant::GetAverage()
{
    return m_Value;
}

bool Constant::IsValid()const
{
    return true;
}
