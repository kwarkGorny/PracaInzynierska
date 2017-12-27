#include "Data.h"

Data::Data() : m_HyperGraph{},m_PTable{}, m_KTable{},m_PDistribution{},m_KDistribution{}
{

}
Data& Data::GetInstance()
{
    static Data data;
    return data;
}
