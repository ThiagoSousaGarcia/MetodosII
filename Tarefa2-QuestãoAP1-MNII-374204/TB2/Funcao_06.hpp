#ifndef Funcao_06_hpp
#define Funcao_06_hpp

#include <math.h>

#include "Funcao.hpp"

class Funcao_06:public Funcao{
public:
    double f(double x){
        return sin(x) + cos(x);
    }
};


#endif /* Funcao_06_hpp */