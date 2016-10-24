#include <GL/gl.h>
#include <GL/glut.h>
#include "objeto3d.h"
#include <iostream>
#include <vector>
using namespace std;

Objeto3D::Objeto3D(){
}

Objeto3D::Objeto3D(const vector <float> &v,const vector <int> &c)
{
    vertices = vertices;
    caras = caras;
}

void Objeto3D::addVertices(const vector<float> &v){
    vertices=v;
}

void Objeto3D::addCaras(const vector<int> &c){
    caras=c;
}

vector <float> Objeto3D::getVertices(){
    return vertices;
}

vector <int> Objeto3D::getCaras(){
    return caras;
}

void Objeto3D::invertirCaras(){
    int tam = caras.size();
    for (int i = 0; i < tam; i++)
    {
        float aux = caras[i];
        caras[i] = caras[tam-1];
        caras[tam-1] = aux;
        tam--;
    }
}

void Objeto3D::invertirVertices(){
    int tam = vertices.size();
    int limite;

    if(tam%2 == 0) limite = tam/2;
    else limite = (tam-3)/2;

    for (int i = 0; i< limite; i+=3)
    {
        float auxX = vertices[i];
        float auxY = vertices[i+1];
        float auxZ = vertices[i+2];
        vertices[i] = vertices[tam -3];
        vertices[i+1] = vertices[tam -2];
        vertices[i+2] = vertices[tam -1];
        vertices[tam-3] = auxX;
        vertices[tam-2] = auxY;
        vertices[tam-1] = auxZ;
        tam-=3;
    }
}



void Objeto3D:: dibujar1(char tipo)
{
    if(tipo == TIPO_PUNTOS){
        glColor3f(1,0,0);
        glPointSize(3);
        glBegin(GL_POINTS);

        for(int i=0; i<vertices.size(); i+=3)
        {
            glVertex3f(vertices[i],vertices[i+1],vertices[i+2]);

        }
        glEnd();
    }else if(tipo == TIPO_LINEAS){

        glColor3f(0,0,1);
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        glBegin(GL_TRIANGLES);

        for(int i=0; i<caras.size(); i+=3)
        {
            glVertex3f(vertices[caras[i]*3],vertices[caras[i]*3+1],vertices[caras[i]*3+2]);
            glVertex3f(vertices[caras[i+1]*3],vertices[caras[i+1]*3+1],vertices[caras[i+1]*3+2]);
            glVertex3f(vertices[caras[i+2]*3],vertices[caras[i+2]*3+1],vertices[caras[i+2]*3+2]);

        }
        glEnd();
    }else if(tipo == TIPO_SOLIDO){
        glColor3f(0,1,0);
        glPointSize(3);
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        glBegin(GL_TRIANGLES);


        for(int i=0; i<caras.size(); i+=3)
        {
            glVertex3f(vertices[caras[i]*3],vertices[caras[i]*3+1],vertices[caras[i]*3+2]);
            glVertex3f(vertices[caras[i+1]*3],vertices[caras[i+1]*3+1],vertices[caras[i+1]*3+2]);
            glVertex3f(vertices[caras[i+2]*3],vertices[caras[i+2]*3+1],vertices[caras[i+2]*3+2]);
        }
        glEnd();
    }else if(tipo == TIPO_AJEDREZ){
        this->dibujar_ajedrez(1,0,0);
    }else if(tipo == TIPO_MULTIMODO){
        this->dibujarMultiModo();
    }

}

void Objeto3D::dibujar2(char tipo,float R,float G,float B){

    if(tipo == TIPO_AJEDREZ){
        this->dibujar_ajedrez(R,G,B);
    }else if(tipo == TIPO_MULTIMODO){
        this->dibujarMultiModo();
    }else{
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
        glEnableClientState(GL_INDEX_ARRAY);
        glIndexPointer(GL_UNSIGNED_INT,0,&caras[0]);
        glPointSize(3);
        glColor3f(R,G,B);

        if(tipo == TIPO_PUNTOS){
            glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
        }else if(tipo == TIPO_LINEAS){
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        }else if(tipo == TIPO_SOLIDO){
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }

        glDrawElements(GL_TRIANGLES,caras.size(),GL_UNSIGNED_INT,&caras[0]);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_INDEX_ARRAY);
    }
}

void Objeto3D::dibujar_ajedrez(float R,float G,float B){
        float NR = R,NG=G,NB=B;

        if(NR==0 && NB==0 && NG==0){
            NR=0.5;NG=0.5;NB=0.5;
        }else if(NR==1 && NB==1 && NG==1){
            NR=0.5;NG=0.5;NB=0.5;
        }else{
             if(NR>=NB && NR>=NG){
                NR/=2;
            }else if(NB>=NR && NB>=NG){
                NB/=2;
            }else if(NG>=NR && NG>=NB){
                NG/=2;
            }
        }

        glPointSize(3);
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        glBegin(GL_TRIANGLES);

        for(int i=0; i<caras.size(); i+=3)
        {
            if(i%2==0) glColor3f(R,G,B);
            else glColor3f(NR,NG,NB);

            glVertex3f(vertices[caras[i]*3],vertices[caras[i]*3+1],vertices[caras[i]*3+2]);
            glVertex3f(vertices[caras[i+1]*3],vertices[caras[i+1]*3+1],vertices[caras[i+1]*3+2]);
            glVertex3f(vertices[caras[i+2]*3],vertices[caras[i+2]*3+1],vertices[caras[i+2]*3+2]);
        }
        glEnd();
}

void Objeto3D::dibujarMultiModo(){
    this->dibujar2(TIPO_SOLIDO,255,243,0);
    this->dibujar2(TIPO_LINEAS,1,0,0);
    this->dibujar2(TIPO_PUNTOS,0,1,0);

}

void Objeto3D::desplazar(float desplazamiento,int x,int y,int z){
    if(x == 1 && y == 0 && z == 0){
        for(int i = 0; i< vertices.size(); i+=3){
            vertices[i] += desplazamiento;
        }
    }else if(x == 0 && y == 1 && z == 0){
        for(int i = 1; i< vertices.size(); i+=3){
            vertices[i] += desplazamiento;
        }
    }else if(x == 0 && y == 0 && z == 1){
        for(int i = 2; i< vertices.size(); i+=3){
            vertices[i] += desplazamiento;
        }
    }
}

void Objeto3D:: invertir(int x,int y,int z) {
    if(x == 1 && y == 0 && z == 0){
        for(int i = 0; i< vertices.size(); i+=3){
            vertices[i] *=-1;
        }
    }else if(x == 0 && y == 1 && z == 0){
        for(int i = 1; i< vertices.size(); i+=3){
            vertices[i] *=-1;
        }
    }else if(x == 0 && y == 0 && z == 1){
        for(int i = 2; i< vertices.size(); i+=3){
            vertices[i] *=-1;
        }
    }
    //invierto vector de caras
    int tam = caras.size();
    for (int i = 0; i < tam; i++)
    {
        float aux = caras[i];
        caras[i] = caras[tam-1];
        caras[tam-1] = aux;
        tam--;
    }
}

Objeto3D::~Objeto3D(){
    vertices.clear();
    caras.clear();
}
