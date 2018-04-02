#include "Statistics.h"
#include <algorithm>
int Statistics::Factorial( int N)
{
    int factorial = 1;
    for(int i = 2 ;i<=N ; ++i)
    {
        factorial *= i;
    }
    return factorial;
}

double Statistics::CalculateAverage(std::vector<int> const& numbers)
{
  return  std::accumulate(numbers.begin(), numbers.end(), 0) / static_cast<double>(numbers.size());
}

double Statistics::CalculateStandardDeviations(std::vector<int> const& numbers)
{
    const double sum = std::accumulate(std::begin(numbers), std::end(numbers), 0.0);
    double average =  sum / numbers.size();
    return Statistics::CalculateStandardDeviations(numbers , average);
}

double Statistics::CalculateStandardDeviations(std::vector<int> const& numbers,double average)
{
    double accum = 0.0;
    std::for_each (std::begin(numbers), std::end(numbers),
                   [&](const int d) {accum += (d - average) * (d - average);});
    return sqrt(accum / (numbers.size()-1));
}

double Statistics::ChiSquareTest(std::vector<double> const& exp,std::vector<double> const& teo)
{
    double sum=0;
    for(int i = 0 ; i < static_cast<int>(teo.size()) ; ++i)
    {
        sum += ((exp[i]-teo[i])*(exp[i]-teo[i])) / exp[i];
    }
    return sum;
}

double Statistics::ChiSquareTest(std::unordered_map<int,double>const& exp,std::vector<double>const& teo)
{
    double sum=0;
    for(auto && it : exp)
    {
        double const1 = (it.second-teo[it.first]);
        sum += const1 * const1 / it.second;
    }
    return sum;
}

std::vector<int> Statistics::GenerateTable(const int size,Distribution& distribution)
{
  std::vector<int> table ;
  table.reserve(size);
  for(int i=0;i < size; ++i)
  {
      table.emplace_back(distribution());
  }
  return table;
}

void Statistics::NormalizeTable(std::vector<int>& table,double normalize)
{
    for(auto&& number : table)
    {
        number /= normalize;
    }
}

std::unordered_map<int,double> Statistics::CalculateHistogram(std::vector<int> const& table)
{
    std::unordered_map<int,double>  histogram;
    histogram.reserve(table.size());
    for(auto&& value : table)
    {
        histogram[value]+=1;
    }
    return histogram;
}

void Statistics::NormalizeHistogram(std::unordered_map<int,double>& histogram)
{
    double sum =0;
    for(auto&& it  : histogram)
    {
        sum += it.second;
    }
    for(auto&& it  : histogram)
    {
        it.second /=sum;
    }
}


