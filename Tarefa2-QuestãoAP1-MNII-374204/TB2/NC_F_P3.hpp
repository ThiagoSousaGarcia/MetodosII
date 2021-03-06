#ifndef NC_F_P3_hpp
#define NC_F_P3_hpp

#include "Integracao.hpp"

class NC_F_P3 : public Integracao
{
public:
    NC_F_P3(Funcao * f, double a, double b, int N, double epsilon);
    
    virtual double integrar();
    
private:
    double  NC_F_P3_integracao(Funcao * f, double a, double b);
    
    Funcao *m_pIntegrando;
    double  m_lInf;
    double  m_lSup;
    double  m_precisao;
    int     m_particao;
};


#endif /* NC_F_P3_hpp */