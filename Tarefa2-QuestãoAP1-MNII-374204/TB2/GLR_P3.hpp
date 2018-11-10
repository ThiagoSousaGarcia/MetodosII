#ifndef GLR_P3_hpp
#define GLR_P3_hpp

#include "Integracao.hpp"

class GLR_P3: public Integracao
{
public:
    GLR_P3(Funcao * f);
    
    virtual double integrar();
    
private:
    Funcao *m_pIntegrando;

};


#endif /* GLR_P3_hpp */