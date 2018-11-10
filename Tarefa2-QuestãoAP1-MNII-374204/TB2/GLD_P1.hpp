#ifndef GLD_P1_hpp
#define GLD_P1_hpp

#include "Integracao.hpp"

class GLD_P1 : public Integracao
{
public:
    GLD_P1(Funcao * f, double a, double b, int N, double epsilon);
    
    virtual double integrar();
    
private:
    double  GLD_P1_integracao(Funcao * f, double a, double b);
    double parametrizacao(double a,double b, double s);

    Funcao *m_pIntegrando;
    double  m_lInf;
    double  m_lSup;
    double  m_precisao;
    int     m_particao;
};


#endif /* GLD_P1_hpp */
