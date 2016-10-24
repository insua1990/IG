#include "semiesfera.h"

Semiesfera::Semiesfera(float radio){
    vector<float> v ;
    v.push_back(radio);v.push_back(0);v.push_back(0);

    vector <float> perfil;
    // Rotamos eje Z
    float grados_reales = 85*PI/180.0;
    float grados_por_div = grados_reales/5;

    float xx,yy,zz;
    float coseno = cos(grados_por_div);
    float seno = sin(grados_por_div);
    perfil=v;
    int cont=0;
    for(int k = 0;k< 5 ;k++){

        xx = (coseno*perfil[cont]) - (seno*perfil[cont+1]);
        yy = (coseno*perfil[cont+1]) + (seno*perfil[cont]);
        zz = perfil[cont+2];

        perfil.push_back(xx);
        perfil.push_back(yy);
        perfil.push_back(zz);
        cont+=3;
    }

    vertices.clear();
    caras.clear();

    vertices = perfil;
    this->revolucionar(0,360,40,0,1,0,true);
}

void Semiesfera::dibujar(char tipo,bool lineas){
    this->dibujar2(tipo,0.7,0.7,0.7);
    if(tipo == TIPO_SOLIDO && lineas){
        glBegin(GL_LINES);
        glLineWidth(10.0);
        glPolygonMode(GL_FRONT,GL_LINE);
        glColor3f(0,0,0);
        for(int i = 0; i< vertices.size()-6; i+=18){
            glVertex3f(vertices[i],vertices[i+1],vertices[i+2]);
            glVertex3f(vertices[(i+18)%720],vertices[(i+19)%720],vertices[(i+20)%720]);
        }
        glEnd();
    }
}
