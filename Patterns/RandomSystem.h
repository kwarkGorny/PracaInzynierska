#ifndef RANDOMSYSTEM_H
#define RANDOMSYSTEM_H

#include<random>

#define RANDOMSYSTEM RandomSystem::GetInstance()

class RandomSystem
{
public:
    static RandomSystem& GetInstance();

    RandomSystem(RandomSystem const&) = delete;
    void operator=(RandomSystem const&) = delete;

    inline std::mt19937 const& GetRandomEngine()const{ return m_RandomEngine; }
    inline std::mt19937 & GetRandomEngine(){ return m_RandomEngine; }
    inline void SetRandomEngine(std::mt19937 const& randomEngine){ m_RandomEngine = randomEngine; }

protected:
    RandomSystem();

private:
    std::mt19937 m_RandomEngine;
};

#endif // RANDOMSYSTEM_H
