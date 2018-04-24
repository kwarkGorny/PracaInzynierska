#include "Statistics.h"
#include <algorithm>
int Statistics::Factorial( int N)noexcept
{
    int factorial = 1;
    for(int i = 2 ;i<=N ; ++i)
    {
        factorial *= i;
    }
    return factorial;
}



double Statistics::CalculateStandardDeviations(std::vector<int> const& numbers,double average)noexcept
{
    double accum = 0.0;
    std::for_each (std::begin(numbers), std::end(numbers),
                   [&](const int d) {accum += (d - average) * (d - average);});
    return sqrt(accum / (numbers.size()-1));
}

double Statistics::ChiSquareTest(std::vector<double> const& exp,std::vector<double> const& teo,const double standDev)noexcept
{
    double sum=0;
    for(int i = 0 ; i < static_cast<int>(teo.size()) ; ++i)
    {
        const double ExpSubTeo = exp[i]-teo[i];
        sum += (ExpSubTeo*ExpSubTeo) / standDev;
    }
    return sum;
}

double Statistics::ChiSquareTest(std::unordered_map<int,double>const& exp,std::vector<double>const& teo,const double standDev)noexcept
{
    double sum=0;
    for(auto && it : exp)
    {
        const double ExpSubTeo = (it.second-teo[it.first]);
        sum += ExpSubTeo * ExpSubTeo / standDev;
    }
    return sum;
}
double Statistics::TStudentTest(double teo,double average,double stdev , int sampleSize )noexcept
{
    return (average - teo)/(stdev/sqrt(sampleSize)) ;
}
std::vector<int> Statistics::GenerateTable(const int size,Distribution& distribution)noexcept
{
  std::vector<int> table ;
  table.reserve(size);
  for(int i=0;i < size; ++i)
  {
      table.emplace_back(distribution());
  }
  return table;
}

void Statistics::NormalizeTable(std::vector<int>& table,double normalize)noexcept
{
    for(auto&& number : table)
    {
        number /= normalize;
    }
}

std::unordered_map<int,double> Statistics::CalculateHistogram(std::vector<int> const& table)noexcept
{
    std::unordered_map<int,double>  histogram;
    for(auto&& value : table)
    {
        histogram[value]+=1;
    }
    return histogram;
}

void Statistics::NormalizeHistogram(std::unordered_map<int,double>& histogram)noexcept
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


