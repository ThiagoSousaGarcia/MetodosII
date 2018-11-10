#include "GLR_P4.hpp"
#include <math.h>

GLR_P4::GLR_P4(Funcao * f)
{
    m_pIntegrando = f;
    
}

double GLR_P4::integrar()
{
    double x1,x2,x3,x4;

    x1 = 0.32254768;
    x2 = 1.74576110;
    x3 = 4.53662029;
    x4 = 9.39507091;

    return ((0.32254768)*m_pIntegrando->f(x1) + (0.35741869)*m_pIntegrando->f(x2) + (0.03888791)*m_pIntegrando->f(x3) + (0.00053929)*m_pIntegrando->f(x4));

}