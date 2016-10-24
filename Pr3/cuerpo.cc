#include "cuerpo.h"
Cuerpo:: Cuerpo (){
}

Cuerpo:: Cuerpo (Ply *ply,Semiesfera *hombro_i,Semiesfera*hombro_d){
        vertices = ply->getVertices();
        caras = ply->getCaras();
        this->revolucionar(0,360,60,0,1,0,true);
        hombro_izq = hombro_i;
        hombro_dch = hombro_d;

}

void Cuerpo::dibujar(char tipo){
        this->dibujar2(tipo,0.7,0.7,0.7);
        // LINEAS CUERPO
        if(tipo == TIPO_SOLIDO){
            glBegin(GL_LINES);
            glLineWidth(10.0);
            glPolygonMode(GL_FRONT,GL_LINE);
            glColor3f(0,0,0);

            int cont1,cont2,cont3;
            cont1 = 0;
            cont2 = 9;
            cont3 = 12;
            for(int i=0; i<60; i++)
            {
               glVertex3f(vertices[cont1],vertices[cont1+1],vertices[cont1+2]);
               glVertex3f(vertices[(cont1+15)%900],vertices[(cont1+16)%900],vertices[(cont1+17)%900]);

               glVertex3f(vertices[cont2],vertices[cont2+1],vertices[cont2+2]);
               glVertex3f(vertices[(cont2+15)%900],vertices[(cont2+16)%900],vertices[(cont2+17)%900]);

               glVertex3f(vertices[cont3],vertices[cont3+1],vertices[cont3+2]);
               glVertex3f(vertices[(cont3+15)%900],vertices[(cont3+16)%900],vertices[(cont3+17)%900]);

               cont1+=15;cont2+=15;cont3+=15;
            }

            // PUERTA
            for(int i = 558; i < 765; i+=3){
                glVertex3f(vertices[i],vertices[i+1],vertices[i+2]);
                glVertex3f(vertices[(i+15)%900],vertices[(i+16)%900],vertices[(i+17)%900]);
            }
            glVertex3f(vertices[558],vertices[559],vertices[560]);
            glVertex3f(vertices[561],vertices[562],vertices[563]);

            glVertex3f(vertices[768],vertices[769],vertices[770]);
            glVertex3f(vertices[771],vertices[772],vertices[773]);

            glEnd();

        }


        // HOMBROS
        glPushMatrix();
            glTranslatef(-1.7,-0.6,0.0);
            glRotatef(90,0.0,0.0,1.0);
            hombro_dch->dibujar(tipo,true);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(1.7,-0.6,0.0);
            glRotatef(270,0.0,0.0,1.0);
            hombro_izq->dibujar(tipo,true);
        glPopMatrix();
}
