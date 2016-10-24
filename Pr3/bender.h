#ifndef _BENDER_H
#define _BENDER_H
#include "pierna.h"
#include "cuerpo.h"
#include "semiesfera.h"
#include "brazo.h"
#include "cabeza.h"


class Bender{
private:

    Pierna *pizq,*pdch;
    Brazo *bizq,*bdch;
    Cabeza *cabeza;
    Cuerpo *cuerpo;
    float gradoC,gradoB,gradoP,velocidadC,velocidadB,velocidadP;

public:

    Bender ();
    void dibujar(char tipo);
    int getGradoC(){return gradoC;};
    int getGradoB(){return gradoB;};
    int getGradoP(){return gradoP;};
    void giraCabezaIzq();
    void giraCabezaDch();
    void masVelocidadCabeza();
    void menosVelocidadCabeza();
    void giraBrazosDelante();
    void giraBrazosDetras();
    void masVelocidadBrazos();
    void menosVelocidadBrazos();
    void giraPiernaDelante();
    void giraPiernaDetras();
    void masVelocidadPierna();
    void menosVelocidadPierna();
};

#endif
