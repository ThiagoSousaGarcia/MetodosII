#include "GLD_P3.hpp"
#include <math.h>

GLD_P3::GLD_P3(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;
    
}


double GLD_P3::parametrizacao(double a,double b,double s){
    double xs;

    xs = ((a+b)/2)+(((b-a)/2)*s);

    return xs;
}

double GLD_P3::integrar()
{
    double integral = 0.0;
    
    if (m_particao >= 1)
    {
        double step = (m_lSup - m_lInf)/m_particao;
        double linf, lsup;
        
        for (int i = 0; i < m_particao; i++)
        {
            linf = m_lInf + i*step;
            lsup = linf   + step;
            
            integral += GLD_P3_integracao(m_pIntegrando, linf, lsup);
        }
        
        return integral;
    }
    else
    {
        int    N           = 1;
        double oldintegral = 0.0;
        double step;
        double linf, lsup;
        
        integral = GLD_P3_integracao(m_pIntegrando, m_lInf, m_lSup);
        
        do
        {
            oldintegral = integral;
            integral    = 0.0;
            
            N = N*2;
            
            step = (m_lSup - m_lInf)/N;
            
            for (int i = 0; i < N; i++)
            {
                linf = m_lInf + i*step;
                lsup = linf   + step;
                
                integral += GLD_P3_integracao(m_pIntegrando, linf, lsup);
            }
            
            
        } while (fabs(integral - oldintegral) > m_precisao);
        
        return integral;
    }
    
}

double GLD_P3::GLD_P3_integracao(Funcao * f, double a, double b){

    double s1,s2,s3,h;

    s1 = parametrizacao(a,b,-sqrt(3/5));
    s2 = parametrizacao(a,b,0);
    s3 = parametrizacao(a,b,sqrt(3/5));

    h = (b-a)/2;

        
    return h*((5.0/9.0)*m_pIntegrando->f(s1) + (8.0/9.0)*m_pIntegrando->f(s2) + (5.0/9.0)*m_pIntegrando->f(s3));
}
