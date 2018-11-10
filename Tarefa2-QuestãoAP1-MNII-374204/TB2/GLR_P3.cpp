#include "GLR_P3.hpp"
#include <math.h>

GLR_P3::GLR_P3(Funcao * f)
{
    m_pIntegrando = f;
    
}

double GLR_P3::integrar()
{
    double x1,x2,x3;

    x1 = 0.41577455;
    x2 = 2.24428036;
    x3 = 6.28994508;

    return ((0.71109300)*m_pIntegrando->f(x1) + (0.27851973)*m_pIntegrando->f(x2) + (0.01038926)*m_pIntegrando->f(x3));
    
}