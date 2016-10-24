#ifndef _SEMIESFERA_H
#define _SEMIESFERA_H

#include "objetorevolucion.h"


class Semiesfera:public ObjetoRevolucion{
public:
    Semiesfera(float radio);
    void dibujar(char tipo,bool lineas);
};
#endif
