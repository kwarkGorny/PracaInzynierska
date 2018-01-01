#ifndef STATISTICS_H
#define STATISTICS_H

#include "Distributions/distribution.h"
#include"Distributions/uniform.h"
#include <vector>
#include<unordered_map>

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Statistics function
*/

class Statistics
{
public:


    static int Factorial(int N);

    static double CalculateAverage(const std::vector<int>& numbers);

    static double CalculateStandardDeviations(const std::vector<int>& numbers);
    static double CalculateStandardDeviations(const std::vector<int>& numbers, double average);

    static double ChiSquareTest(const std::vector<double>& exp, const std::vector<double>& teo);
    static double ChiSquareTest(const std::unordered_map<int,double>& exp, const std::vector<double> &teo);

    static std::vector<int> GenerateTable(const size_t size , Distribution& distribution);

    static std::unordered_map<int,double> CalculateHistogram(const std::vector<int> &table);
    static void NormalizeHistogram(std::unordered_map<int,double>& histogram);


    static void NormalizeTable(std::vector<int>& table,double normalize);

    /*
    static std::vector<int> GenerateTableParallel(const size_t size , Distribution& distribution);
    static std::vector<int> FisherYatesShuffle(std::size_t size, std::size_t max_size);
    */

protected:
private:
    Statistics();
};

#endif // STATISTICS_H



/*
template<class BidiIter >
BidiIter random_unique(BidiIter begin, BidiIter end, size_t num_random)
{
    size_t left = std::distance(begin, end);
    while (--num_random)
    {
        BidiIter r = begin;
        std::advance( r , Uniform::get( 0 , left ) );
        std::swap(*begin, *r);
        ++begin;
        --left;
    }
    return begin;
}*/
