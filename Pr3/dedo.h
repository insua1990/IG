#ifndef _DEDO_H
#define _DEDO_H
#include "objetorevolucion.h"
#include "ply.h"


class Dedo:public ObjetoRevolucion{
public:
    Dedo();
    Dedo (Ply *ply);
    void dibujar(char tipo);
};
#endif
