#include "brazo.h"

Brazo::Brazo(){}

Brazo::Brazo(Ply *ply,Mano *m){
    vertices = ply->getVertices();
    caras = ply->getCaras();
    this->revolucionar(0,360,20,0,1,0,true);
    mano = m;
}

void Brazo::dibujar(char tipo){

    this->dibujar2(tipo,0.47,0.47,0.47);

    if(tipo == TIPO_SOLIDO){
        glBegin(GL_LINES);
        glLineWidth(10.0);
        glPolygonMode(GL_FRONT,GL_LINE);
        glColor3f(0,0,0);

        for(int i=0; i<vertices.size()-6; i+=3)
        {
            glVertex3f(vertices[i],vertices[i+1],vertices[i+2]);
            glVertex3f(vertices[(i+18)%360],vertices[(i+19)%360],vertices[(i+20)%360]);
        }
        glEnd();
    }

    glPushMatrix();
        glTranslatef(0.0,-3.0,0.0);
        mano->dibujar(tipo);
    glPopMatrix();
}
