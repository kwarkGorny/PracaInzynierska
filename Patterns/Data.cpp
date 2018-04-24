#include "Data.h"

Data::Data() : m_HyperGraph{},m_PTable{}, m_KTable{},m_PDistribution{},m_KDistribution{}
{
}

Data& Data::GetInstance()noexcept
{
    static Data data;
    return data;
}

void Data::Reset()noexcept
{
    m_HyperGraph.Reset();
    m_PTable.clear();
    m_KTable.clear();

    m_PDistribution.reset({});
    m_KDistribution.reset({});
}
