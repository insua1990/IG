#ifndef _DIENTES_H
#define _DIENTES_H

#include "objetorevolucion.h"

class Dientes:public ObjetoRevolucion{
    public:
        Dientes(Ply *ply);
        void dibujar(char tipo);
};

#endif
