#ifndef UTILS_H
#define UTILS_H

#include <QVector>
#include<unordered_map>
#include<vector>
#include<map>
namespace  Utils
{
    template<class T,class Q>
    std::tuple<QVector<Q>,QVector<Q>> ToQVector(const std::unordered_map<T,Q>& data)noexcept;

    template<class T>
    std::tuple<QVector<T>,QVector<T>> ToQVector(const std::vector<T>& data)noexcept;


    template<typename KeyType, typename ValueType>
    std::pair<KeyType,ValueType> GetMax( const std::unordered_map<KeyType,ValueType>& x ) noexcept;

    template<typename KeyType, typename ValueType>
    std::vector<KeyType> GetKeys( std::unordered_map<KeyType,ValueType>&& histogram ) noexcept;

};

template<class T,class Q>
std::tuple<QVector<Q>,QVector<Q>> Utils::ToQVector(const std::unordered_map<T,Q>& data)noexcept
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
std::tuple<QVector<T>,QVector<T>> Utils::ToQVector(const std::vector<T>& data)noexcept
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
template<typename KeyType, typename ValueType>
std::pair<KeyType,ValueType> Utils::GetMax( const std::unordered_map<KeyType,ValueType>& x )noexcept
{
      return *std::max_element(x.begin(), x.end(), [] (auto&& p1, auto&& p2) {
            return p1.second < p2.second;
      });
}
template<typename KeyType, typename ValueType>
std::vector<KeyType> Utils::GetKeys(std::unordered_map<KeyType,ValueType>&& histogram )noexcept
{
    std::vector<KeyType> keys;
    keys.reserve(histogram.size());
    for(auto&& imap: histogram)
        keys.emplace_back(imap.first);
    return keys;
}

#endif // UTILS_H
