#include "distribution.h"

std::mt19937 Distribution::m_RandomNumberEngine(std::random_device{}());

Distribution::Distribution()
{
}
