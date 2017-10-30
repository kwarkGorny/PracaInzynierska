#ifndef UNIFORM_H
#define UNIFORM_H
#include<random>
#include"distribution.h"

class Uniform : public Distribution
{
public:
    Uniform(int start,int end);
    virtual ~Uniform(){}

    int operator ()() ;

    static int get(const int min ,const int max);
    static std::vector<double> GetTheoretical(int N,double min,double max);

    virtual std::vector<double> GetTheoretical(int N);



protected:
private:
    std::uniform_int_distribution<int> m_Uniform;


};

#endif // UNIFORM_H
