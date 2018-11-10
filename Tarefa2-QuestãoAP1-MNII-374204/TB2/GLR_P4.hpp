#ifndef GLR_P4_hpp
#define GLR_P4_hpp

#include "Integracao.hpp"

class GLR_P4: public Integracao
{
public:
    GLR_P4(Funcao * f);
    
    virtual double integrar();
    
private:
    Funcao *m_pIntegrando;

};


#endif /* GLR_P4_hpp */