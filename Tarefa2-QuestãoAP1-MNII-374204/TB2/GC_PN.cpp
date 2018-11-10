#include "GC_PN.hpp"
#include <math.h>

GC_PN::GC_PN(Funcao * f, int N)
{
    m_pIntegrando = f;
    m_particao    = N;
    
}


double GC_PN::parametrizacao(double k){
    double xk;

    xk = cos(((k - (1.0/2.0)) / m_particao) * M_PI);

    return xk;
}

double GC_PN::integrar()
{
    double integral = 0.0;
    
    for (int i = 1; i <= m_particao; i++){
        integral += GC_PN_integracao(m_pIntegrando, i);
    }
        
    return (M_PI/m_particao) * integral;
    
}

double GC_PN::GC_PN_integracao(Funcao * f, int i){

    double ki;

    ki = parametrizacao(i);

    return m_pIntegrando->f(ki);
}
