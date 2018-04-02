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

namespace Statistics
{

    int Factorial(int N);

     double CalculateAverage(const std::vector<int>& numbers);

     double CalculateStandardDeviations(std::vector<int> const& numbers);
     double CalculateStandardDeviations(std::vector<int> const& numbers, double average);

     double ChiSquareTest(std::vector<double> const& exp, const std::vector<double>& teo);
     double ChiSquareTest(std::unordered_map<int,double> const& exp, const std::vector<double> &teo);

     std::vector<int> GenerateTable(const int size , Distribution& distribution);

     std::unordered_map<int,double> CalculateHistogram(std::vector<int> const&table);

     void NormalizeHistogram(std::unordered_map<int,double>& histogram);
     void NormalizeTable(std::vector<int>& table,double normalize);

};

#endif // STATISTICS_H




