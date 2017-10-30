#include "binomal.h"

Binomal::Binomal() : Distribution () ,m_Binomal(100)
{

}
int Binomal::operator() ()
{
    return 5;
}
