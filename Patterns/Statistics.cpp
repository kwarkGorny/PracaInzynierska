#include "Statistics.h"
#include <algorithm>
Statistics::Statistics()
{
}

int Statistics::Factorial( int N)
{
    int factorial = 1;
    for(int i = 2 ;i<=N ; ++i)
    {
        factorial *= i;
    }
    return factorial;
}

double Statistics::CalculateAverage(const std::vector<int>& numbers)
{
  return  std::accumulate(numbers.begin(), numbers.end(), 0) / static_cast<double>(numbers.size());
}
double Statistics::CalculateStandardDeviations(const std::vector<int>& numbers)
{
    double sum = std::accumulate(std::begin(numbers), std::end(numbers), 0.0);
    double average =  sum / numbers.size();

    return Statistics::CalculateStandardDeviations(numbers , average);
}
double Statistics::CalculateStandardDeviations(const std::vector<int>& numbers,double average)
{
    double accum = 0.0;
    std::for_each (std::begin(numbers), std::end(numbers),
                   [&](const int d) {accum += (d - average) * (d - average);});
    return sqrt(accum / (numbers.size()-1));
}

double Statistics::ChiSquareTest(const std::vector<double>& exp,const std::vector<double>& teo)
{
    double sum=0;
    for(size_t i = 0 ; i < teo.size() ; ++i)
    {
        sum += ((exp[i]-teo[i])*(exp[i]-teo[i])) / exp[i];
    }
    return sum;
}
double Statistics::ChiSquareTest(const std::unordered_map<int,double>& exp,const std::vector<double>& teo)
{
    double sum=0;
    for(auto const& it : exp)
    {
        double const1 = (it.second-teo[it.first]);
        sum += const1 * const1 / it.second;
    }
    return sum;
}


std::vector<int> Statistics::GenerateTable(const size_t size,Distribution& distribution)
{
  std::vector<int> table ;
  table.reserve(size);
  for(size_t i=0;i < size; ++i)
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
std::unordered_map<int,double> Statistics::CalculateHistogram(const std::vector<int>& table)
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
/*
std::vector<int> Statistics::GenerateTableParallel(const size_t size , Distribution& distribution)
{
    std::vector<int> table(size) ;
    return table;
}
std::vector<int> Statistics::FisherYatesShuffle(std::size_t size, std::size_t max_size)
{
    std::vector<int> b(size);

    for(std::size_t i = 0; i != max_size; ++i) {

        std::uniform_int_distribution<> dis(0, i);
       /std::size_t j = dis(m_RandomNumberEngine);

        if(j < b.size()) {
            if(i < j) {
                b[i] = b[j];
            }
            b[j] = i;
        }
    }
    return b;
}
*/
