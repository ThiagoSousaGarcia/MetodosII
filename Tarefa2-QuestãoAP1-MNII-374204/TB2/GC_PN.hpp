#ifndef GC_PN_hpp
#define GC_PN_hpp

#include "Integracao.hpp"

class GC_PN: public Integracao
{
public:
    GC_PN(Funcao * f, int N);
    
    virtual double integrar();
    
private:
    double  GC_PN_integracao(Funcao * f, int i);
    double parametrizacao(double k);

    Funcao *m_pIntegrando;
    int     m_particao;
};


#endif /* GC_PN_hpp */