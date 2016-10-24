#include "pierna.h"
Pierna:: Pierna (){

}

Pierna:: Pierna (Ply *ply,Semiesfera *p){
        vertices = ply->getVertices();
        caras = ply->getCaras();
        this->revolucionar(0,360,20,0,1,0,true);
        pie = p;
}

void Pierna::dibujar(char tipo){
        // PIES
        glPushMatrix();
            glTranslatef(0.0,-4.0,0.0);
            pie->dibujar(tipo,true);
        glPopMatrix();


        this->dibujar2(tipo,0.47,0.47,0.47);
        if(tipo == TIPO_SOLIDO){
            glBegin(GL_LINES);
            glLineWidth(10.0);
            glPolygonMode(GL_FRONT,GL_LINE);
            glColor3f(0,0,0);

            for(int i=0; i<vertices.size()-6; i+=3)
            {
                glVertex3f(vertices[i],vertices[i+1],vertices[i+2]);
                glVertex3f(vertices[(i+24)%480],vertices[(i+25)%480],vertices[(i+26)%480]);
            }
            glEnd();
        }

}
