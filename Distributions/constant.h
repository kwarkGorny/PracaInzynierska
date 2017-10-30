#ifndef CONSTANT_H
#define CONSTANT_H
#include"Distributions/distribution.h"

class Constant : public Distribution
{
public:
    Constant(int value);
    virtual ~Constant(){}

    int operator() ();

    virtual std::vector<double> GetTheoretical(int N);



protected:
    const int value;
private:

};

#endif // CONSTANT_H
