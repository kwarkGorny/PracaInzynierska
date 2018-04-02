#ifndef UTILS_H
#define UTILS_H

#include <QVector>
#include<unordered_map>
#include<vector>

namespace  Utils
{
    template<class T,class Q>
    std::tuple<QVector<Q>,QVector<Q>> ToQVector(const std::unordered_map<T,Q>& data);

    template<class T>
    std::tuple<QVector<T>,QVector<T>> ToQVector(const std::vector<T>& data);
};

template<class T,class Q>
std::tuple<QVector<Q>,QVector<Q>> Utils::ToQVector(const std::unordered_map<T,Q>& data)
{
    QVector<Q> x;
    QVector<Q> y;
    x.reserve(data.size());
    y.reserve(data.size());
    for (const auto& value : data)
    {
      x.push_back(value.first);
      y.push_back(value.second);
    }
    return std::tie(x,y);
}

template<class T>
std::tuple<QVector<T>,QVector<T>> Utils::ToQVector(const std::vector<T>& data)
{
    QVector<T> x;
    QVector<T> y;
    x.reserve(data.size());
    y.reserve(data.size());
    for (int i=0; i <static_cast<int>(data.size()); ++i)
    {
        if(data[i] !=0)
        {
            x.push_back(i);
            y.push_back(data[i]);
        }
    }
    return std::tie(x,y);
}

#endif // UTILS_H
