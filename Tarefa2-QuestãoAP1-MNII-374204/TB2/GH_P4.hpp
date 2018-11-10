#ifndef GH_P4_hpp
#define GH_P4_hpp

#include "Integracao.hpp"

class GH_P4: public Integracao
{
public:
    GH_P4(Funcao * f);
    
    virtual double integrar();
    
private:
    Funcao *m_pIntegrando;
};


#endif /* GH_P4_hpp */