#ifndef _FRONTAL_H
#define _FRONTAL_H

#include "ojo.h"
#include "ply.h"

class Frontal{
    private:
        Ojo *ojo_izq,*ojo_dch;
        Ply *foco_ext,*foco_int;
    public:
        Frontal(Ojo *ojo,Ply *focoE,Ply *focoI);
        void dibujar(char tipo);
};

#endif
