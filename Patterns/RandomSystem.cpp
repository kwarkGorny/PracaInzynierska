#include "RandomSystem.h"

RandomSystem::RandomSystem() : m_RandomEngine(std::random_device{}())
{
}

RandomSystem& RandomSystem::GetInstance()noexcept
{
    static RandomSystem randomSystem;
    return randomSystem;
}
