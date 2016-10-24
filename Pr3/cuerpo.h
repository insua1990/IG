#ifndef _CUERPO_H
#define _CUERPO_H
#include "objetorevolucion.h"
#include "ply.h"
#include "semiesfera.h"

class Cuerpo:public ObjetoRevolucion{
private:
    Semiesfera *hombro_izq;
    Semiesfera *hombro_dch;

public:


    Cuerpo ();
    Cuerpo (Ply *ply,Semiesfera *hombro_i,Semiesfera*hombro_d);
    void dibujar(char tipo);
};
#endif
