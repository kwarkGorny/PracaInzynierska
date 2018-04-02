#ifndef DATA_H
#define DATA_H

#include"Distributions/distribution.h"
#include"HyperGraph/HyperGraph.h"
#include <memory>
#include <vector>

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Main Data contener
*/

#define DATA Data::GetInstance()

class Data
{
public:
    ~Data(){}

    static Data& GetInstance();

    Data(Data const&) = delete;
    void operator=(Data const&) = delete;

    void Reset();

    inline HyperGraph const& GetHyperGraph()const{ return m_HyperGraph; }
    inline HyperGraph& GetHyperGraph(){ return m_HyperGraph; }
    inline void SetHyperGraph(HyperGraph const& hyperGraph){ m_HyperGraph = hyperGraph; }
    inline void SetHyperGraph(HyperGraph && hyperGraph){ m_HyperGraph = std::move(hyperGraph); }

    inline std::vector<int> const& GetKTable()const{ return m_KTable; }
    inline std::vector<int>& GetKTable(){ return m_KTable; }
    inline void SetKTable(std::vector<int>const& kTable){ m_KTable = kTable; }
    inline void SetKTable(std::vector<int>&& kTable){ m_KTable =std::move(kTable); }

    inline std::vector<int> const& GetPTable()const{ return m_PTable; }
    inline std::vector<int>& GetPTable(){ return m_PTable; }
    inline void SetPTable(std::vector<int>const& pTable){ m_PTable = pTable; }
    inline void SetPTable(std::vector<int>&& pTable){ m_PTable =std::move(pTable); }

    inline Distribution const* GetPDistribution()const{ return m_PDistribution.get(); }
    inline Distribution * GetPDistribution(){ return m_PDistribution.get(); }
    inline void SetPDistribution(Distribution *distr){ m_PDistribution.reset(distr); }

    inline Distribution const* GetKDistribution()const{ return m_KDistribution.get(); }
    inline Distribution * GetKDistribution(){ return m_KDistribution.get(); }
    inline void SetKDistribution(Distribution *distr){ m_KDistribution.reset(distr); }

protected:
    Data();

private:
    HyperGraph m_HyperGraph;

    std::vector<int> m_PTable;
    std::vector<int> m_KTable;

    std::unique_ptr<Distribution> m_PDistribution;
    std::unique_ptr<Distribution> m_KDistribution;
};
#endif // DATA_H
