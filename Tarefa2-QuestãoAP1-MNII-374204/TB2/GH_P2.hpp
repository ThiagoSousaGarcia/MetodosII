#ifndef GH_P2_hpp
#define GH_P2_hpp

#include "Integracao.hpp"

class GH_P2: public Integracao
{
public:
    GH_P2(Funcao * f);
    
    virtual double integrar();
    
private:

    Funcao *m_pIntegrando;
};


#endif /* GH_P2_hpp */