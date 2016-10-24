#ifndef _OJO_H
#define _OJO_H

#include "objetorevolucion.h"


class Ojo:public ObjetoRevolucion{
public:
    Ojo(float radio);
    void dibujar(char tipo,bool lineas);
};
#endif
