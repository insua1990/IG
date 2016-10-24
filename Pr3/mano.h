#ifndef _MANO_H
#define _MANO_H
#include "objetorevolucion.h"
#include "ply.h"
#include "dedo.h"

class Mano:public ObjetoRevolucion{
private:
    Dedo *dedo;
public:
    Mano();
    Mano (Ply *ply,Dedo *d);
    void dibujar(char tipo);
};
#endif
