#ifndef Funcao_07_hpp
#define Funcao_07_hpp

#include <math.h>

#include "Funcao.hpp"

class Funcao_07:public Funcao{
public:
    double f(double x){
        return x/tan(x);
    }
};


#endif /* Funcao_06_hpp */