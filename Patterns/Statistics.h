#ifndef STATISTICS_H
#define STATISTICS_H

#include "Distributions/distribution.h"
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

    static double CalculateStandardDeviations(std::vector<int> const& numbers);
    static double CalculateStandardDeviations(std::vector<int> const& numbers, double average);

    static double ChiSquareTest(std::vector<double> const& exp, const std::vector<double>& teo);
    static double ChiSquareTest(std::unordered_map<int,double> const& exp, const std::vector<double> &teo);

    static std::vector<int> GenerateTable(const size_t size , Distribution& distribution);

    static std::unordered_map<int,double> CalculateHistogram(std::vector<int> const&table);

    static void NormalizeHistogram(std::unordered_map<int,double>& histogram);
    static void NormalizeTable(std::vector<int>& table,double normalize);

    /*
    static std::vector<int> GenerateTableParallel(const size_t size , Distribution& distribution);
    static std::vector<int> FisherYatesShuffle(std::size_t size, std::size_t max_size);
    */

protected:
private:
    Statistics(){}
};

#endif // STATISTICS_H




