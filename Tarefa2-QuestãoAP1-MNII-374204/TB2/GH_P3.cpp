#include "GH_P3.hpp"
#include <math.h>

GH_P3::GH_P3(Funcao * f)
{
    m_pIntegrando = f;
    
}

double GH_P3::integrar()
{
    double x1,x2,x3;

    x1 = 1.22474487;
    x2 = 0.0;
    x3 = -1.22474487;
       
    return ((0.29540897)*m_pIntegrando->f(x1) + (1.18163590)*m_pIntegrando->f(x2) + (0.29540897)*m_pIntegrando->f(x3));

}