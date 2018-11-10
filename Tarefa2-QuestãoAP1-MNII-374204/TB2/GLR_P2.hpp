#ifndef GLR_P2_hpp
#define GLR_P2_hpp

#include "Integracao.hpp"

class GLR_P2: public Integracao
{
public:
    GLR_P2(Funcao * f);
    
    virtual double integrar();
    
private:
    Funcao *m_pIntegrando;
    
};


#endif /* GLR_P2_hpp */