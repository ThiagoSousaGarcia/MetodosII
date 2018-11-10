#ifndef Funcao_05_hpp
#define Funcao_05_hpp

#include <math.h>

#include "Funcao.hpp"

class Funcao_05:public Funcao{
public:
    double f(double x){
        return (x*x*x*x + 3);
    }
};


#endif /* Funcao_05_hpp */