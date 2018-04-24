#ifndef STATISTICS_H
#define STATISTICS_H

#include "Distributions/distribution.h"
#include <vector>
#include<unordered_map>
#include<algorithm>
/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Statistics function
*/

namespace Statistics
{
    int Factorial(int N)noexcept;

    template<class T>
    double CalculateAverage(const std::vector<T>& numbers)noexcept;
    template<class T>
    double CalculateMedian(const std::vector<T>& numbers)noexcept;

    double CalculateStandardDeviations(std::vector<int> const& numbers)noexcept;
    double CalculateStandardDeviations(std::vector<int> const& numbers, double average)noexcept;

    double ChiSquareTest(std::vector<double> const& exp, const std::vector<double>& teo,const double standDev)noexcept;
    double ChiSquareTest(std::unordered_map<int,double> const& exp, const std::vector<double> &teo,const double standDev)noexcept;

    double TStudentTest(double teo,double average,double stdev, int sampleSize)noexcept;

    std::vector<int> GenerateTable(const int size , Distribution& distribution)noexcept;

    std::unordered_map<int,double> CalculateHistogram(std::vector<int> const&table)noexcept;

    void NormalizeHistogram(std::unordered_map<int,double>& histogram)noexcept;
    void NormalizeTable(std::vector<int>& table,double normalize)noexcept;

};

template<class T>
double Statistics::CalculateAverage(std::vector<T>const& numbers)noexcept
{
  return  std::accumulate(numbers.begin(), numbers.end(), 0) / static_cast<double>(numbers.size());
}
template<class T>
double Statistics::CalculateMedian(std::vector<T>const& numbers)noexcept
{
    auto v = numbers;
    const auto n = v.size() / 2;
    std::nth_element(v.begin(), v.begin()+n, v.end());
    return v[n];
}
#endif // STATISTICS_H




