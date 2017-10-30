#include "constant.h"

Constant::Constant(int value) :Distribution () , value(value)
{
}
int Constant::operator()()
{
    return value;
}
std::vector<double> Constant::GetTheoretical(int N)
{
    std::vector<double> prob(N);
    prob[value] = 1;

    return prob;
}
