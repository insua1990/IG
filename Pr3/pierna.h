#ifndef _PIERNA_H
#define _PIERNA_H
#include "objetorevolucion.h"
#include "ply.h"
#include "semiesfera.h"

class Pierna:public ObjetoRevolucion{
private:
    Semiesfera *pie;

public:

    Pierna();
    Pierna (Ply *ply,Semiesfera *p);
    void dibujar(char tipo);
};
#endif
