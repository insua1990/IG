#include "cabeza.h"

Cabeza::Cabeza(){}

Cabeza::Cabeza(Semiesfera *t,ObjetoRevolucion *s,ObjetoRevolucion *n,Dientes *d,ObjetoRevolucion *c,Frontal *f,ObjetoRevolucion *a){
    tapa = t;
    sien = s;
    nuca = n;
    dientes = d;
    cuello = c;
    frontal = f;
    antena = a;
}

void Cabeza::dibujar(char tipo){

    glPushMatrix();
        glTranslatef(0.0,2.9,0.0);
        glScalef(1,0.7,1);
        tapa->dibujar(tipo,false);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0,2.9,0.0);
        sien->dibujar2(tipo,0.7,0.7,0.7);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0,1.6,0.0);
        glRotatef(330,0.0,1.0,0.0);
        nuca->dibujar2(tipo,0.7,0.7,0.7);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0,1.1,0.0);
        cuello->dibujar2(tipo,0.7,0.7,0.7);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0,2.34,0.0);
        frontal->dibujar(tipo);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0,3.5,0.0);
        antena->dibujar2(tipo,0.7,0.7,0.7);
    glPopMatrix();

    dientes->dibujar(tipo);

}
