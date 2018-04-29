#ifndef FILEOPERATION_H
#define FILEOPERATION_H
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
class FileOperation
{
public:
    FileOperation();
    template<class T>
    static void SaveToFile(std::string const& nameOfFile , std::vector<T>const& data);
    template<class T>
    static void SaveToFile(std::string const& nameOfFile , std::unordered_map<int,T> const& data);

};

template<class T>
void FileOperation::SaveToFile(std::string const& nameOfFile , std::vector<T>const& data)
{
    std::ofstream file (nameOfFile);
    if(file.is_open())
    {
        file<<data.size()<<'\n';
        int i=0;
        for(auto const& value : data)
        {
            file<< i << " " <<value << '\n';
            ++i;
        }
        file.flush();
        file.close();
    }
}
template<class T>
void FileOperation::SaveToFile(std::string const& nameOfFile ,std::unordered_map<int,T> const& data)
{
    std::ofstream file (nameOfFile);
    if(file.is_open())
    {
        file<<data.size()<<'\n';
        for(auto const& value : data)
        {
            file<< value.first << " " <<value.second << '\n';
        }
        file.flush();
        file.close();
    }
}

#endif // FILEOPERATION_H
