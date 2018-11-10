#include "GH_P4.hpp"
#include <math.h>

GH_P4::GH_P4(Funcao * f)
{
    m_pIntegrando = f;
    
}

double GH_P4::integrar()
{
    double x1,x2,x3,x4;

    x1 = 0.52464762;
    x2 = -0.52464762;
    x3 = 1.65068012;
    x4 = -1.65068012;
       
    return ((0.80491409)*m_pIntegrando->f(x1) + (0.80491409)*m_pIntegrando->f(x2) + (0.08131283)*m_pIntegrando->f(x3) + (0.08131283)*m_pIntegrando->f(x4));
   
}