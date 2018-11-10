#ifndef GH_P3_hpp
#define GH_P3_hpp

#include "Integracao.hpp"

class GH_P3: public Integracao
{
public:
    GH_P3(Funcao * f);
    
    virtual double integrar();
    
private:
    Funcao *m_pIntegrando;

};


#endif /* GH_P3_hpp */