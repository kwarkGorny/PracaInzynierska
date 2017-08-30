#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H
#include<random>

class RandomNumber
{
public:
    RandomNumber();

//    int getUniform(const int min,const int max)const;
//    int getPoisson(const int value)const;

protected:
private:
    std::default_random_engine engine;

};

#endif // RANDOMNUMBER_H
