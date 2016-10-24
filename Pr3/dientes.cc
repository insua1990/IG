#include "dientes.h"

Dientes::Dientes(Ply *ply){
    vertices = ply->getVertices();
    caras = ply->getCaras();
    this->revolucionar(0,120,14,0,1,0,false);
}

void Dientes::dibujar(char tipo){

    glPushMatrix();
        glTranslatef(0.0,1.6,0.0);
        glRotatef(210,0,1,0);
        this->dibujar2(tipo,1,1,0.6);


        if(tipo == TIPO_SOLIDO){
            glBegin(GL_LINES);
                glLineWidth(10.0);
                glPolygonMode(GL_FRONT,GL_LINE);
                glColor3f(0,0,0);

                for(int i=0; i<vertices.size()-12; i+=3)
                {
                    glVertex3f(vertices[i],vertices[i+1],vertices[i+2]);
                    glVertex3f(vertices[(i+12)],vertices[(i+13)],vertices[(i+14)]);
                }


                glVertex3f(vertices[36],vertices[37],vertices[38]);
                glVertex3f(vertices[39],vertices[40],vertices[41]);
                glVertex3f(vertices[39],vertices[40],vertices[41]);
                glVertex3f(vertices[42],vertices[43],vertices[44]);
                glVertex3f(vertices[42],vertices[43],vertices[44]);
                glVertex3f(vertices[45],vertices[46],vertices[47]);

                glVertex3f(vertices[36+(4*12)],vertices[37+(4*12)],vertices[38+(4*12)]);
                glVertex3f(vertices[39+(4*12)],vertices[40+(4*12)],vertices[41+(4*12)]);
                glVertex3f(vertices[39+(4*12)],vertices[40+(4*12)],vertices[41+(4*12)]);
                glVertex3f(vertices[42+(4*12)],vertices[43+(4*12)],vertices[44+(4*12)]);
                glVertex3f(vertices[42+(4*12)],vertices[43+(4*12)],vertices[44+(4*12)]);
                glVertex3f(vertices[45+(4*12)],vertices[46+(4*12)],vertices[47+(4*12)]);

                glVertex3f(vertices[36+(4*12)+(4*12)],vertices[37+(4*12)+(4*12)],vertices[38+(4*12)+(4*12)]);
                glVertex3f(vertices[39+(4*12)+(4*12)],vertices[40+(4*12)+(4*12)],vertices[41+(4*12)+(4*12)]);
                glVertex3f(vertices[39+(4*12)+(4*12)],vertices[40+(4*12)+(4*12)],vertices[41+(4*12)+(4*12)]);
                glVertex3f(vertices[42+(4*12)+(4*12)],vertices[43+(4*12)+(4*12)],vertices[44+(4*12)+(4*12)]);
                glVertex3f(vertices[42+(4*12)+(4*12)],vertices[43+(4*12)+(4*12)],vertices[44+(4*12)+(4*12)]);
                glVertex3f(vertices[45+(4*12)+(4*12)],vertices[46+(4*12)+(4*12)],vertices[47+(4*12)+(4*12)]);


            glEnd();
        }
    glPopMatrix();
}
