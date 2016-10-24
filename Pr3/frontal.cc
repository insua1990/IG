#include "frontal.h"

Frontal::Frontal(Ojo *ojo,Ply *focoE,Ply *focoI){
    ojo_dch = ojo;
    ojo_izq = ojo;
    foco_ext = focoE;
    foco_int = focoI;
}

void Frontal::dibujar(char tipo){
    glPushMatrix();
        glTranslatef(-0.34,0,1.3);
        glRotatef(90,1.0,0.0,0.0);
        ojo_dch->dibujar(tipo,false);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.34,0,1.3);
        glRotatef(90,1.0,0.0,0.0);
        ojo_izq->dibujar(tipo,false);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0,0.36,0.5);
        foco_ext->dibujar2(tipo,0.7,0.7,0.7);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0,0.26,0.51);
        foco_int->dibujar2(tipo,0,0,0);
    glPopMatrix();

}
