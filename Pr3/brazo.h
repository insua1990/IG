#ifndef _BRAZO_H
#define _BRAZO_H
#include "objetorevolucion.h"
#include "ply.h"
#include "mano.h"

class Brazo:public ObjetoRevolucion{
private:
    Mano *mano;
    float gradoM,velocidadM;
public:
    Brazo();
    Brazo (Ply *ply,Mano *m);
    void dibujar(char tipo);
    void giraManoIzq();
    void giraManoDch();
    void masVelocidadMano();
    void menosVelocidadMano();
};
#endif
