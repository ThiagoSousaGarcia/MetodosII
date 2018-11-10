#include "GH_P2.hpp"
#include <math.h>

GH_P2::GH_P2(Funcao * f)
{
    m_pIntegrando = f;
    
}

double GH_P2::integrar()
{
    double x1,x2;

    x1 = 0.70710678;
    x2 = -0.70710678;

    return ((0.88622692)*m_pIntegrando->f(x1) + (0.88622692)*m_pIntegrando->f(x2));
    
}
