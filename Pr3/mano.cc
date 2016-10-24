#include "mano.h"

Mano::Mano(){}

Mano::Mano(Ply *ply,Dedo *d){
    vertices = ply->getVertices();
    caras = ply->getCaras();
    this->revolucionar(0,360,10,0,1,0,true);
    dedo =d;
}

void Mano::dibujar(char tipo){

    this->dibujar2(tipo,0.7,0.7,0.7);
    if(tipo == TIPO_SOLIDO){
        glBegin(GL_LINES);
        glLineWidth(10.0);
        glPolygonMode(GL_FRONT,GL_LINE);
        glColor3f(0,0,0);
        for(int i = 0; i<vertices.size()-6; i+=3){
            glVertex3f(vertices[i],vertices[i+1],vertices[i+2]);
            glVertex3f(vertices[(i+6)%60],vertices[(i+7)%60],vertices[(i+8)%60]);

        }
        glEnd();
    }

    glPushMatrix();
        glTranslatef(0.0,-0.6,0.25);
        dedo->dibujar(tipo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.25,-0.6,-0.25);
        dedo->dibujar(tipo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.25,-0.6,-0.25);
        dedo->dibujar(tipo);
    glPopMatrix();
}

