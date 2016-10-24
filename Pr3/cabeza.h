#ifndef _CABEZA_H
#define _CABEZA_H

#include "frontal.h"
#include "objetorevolucion.h"
#include "semiesfera.h"
#include "dientes.h"

class Cabeza{
    private:
        Frontal *frontal;
        ObjetoRevolucion *cuello,*nuca ,*sien,*antena;
        Semiesfera *tapa;
        Dientes *dientes;
    public:
        Cabeza();
        Cabeza(Semiesfera *t,ObjetoRevolucion *s,ObjetoRevolucion *n,Dientes *d,ObjetoRevolucion *c,Frontal *f,ObjetoRevolucion *a);
        void dibujar(char tipo);
};

#endif
