#include "GLR_P2.hpp"
#include <math.h>

GLR_P2::GLR_P2(Funcao * f)
{
    m_pIntegrando = f;
    
}

double GLR_P2::integrar()
{
    double x1,x2;

    x1 = 0.58578643;
    x2 = 3.41421356;

    return ((0.85355339)*m_pIntegrando->f(x1) + (0.14644660)*m_pIntegrando->f(x2));

    
}