#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include <GL/glu.h>
#include <iostream>
#include <vector>
using namespace std;
class Objeto3D
{
    protected:
        vector<float> vertices;
        vector<int> caras;

    public:
        const static char TIPO_PUNTOS = 'p';
        const static char TIPO_LINEAS = 'l';
        const static char TIPO_SOLIDO = 's';
        const static char TIPO_AJEDREZ = 'a';
        const static char TIPO_MULTIMODO = 'm';

        Objeto3D();
        Objeto3D(const vector <float> &v,const vector <int> &c);
        ~Objeto3D();

        void addVertices(const vector<float> &v);
        vector <float> getVertices();
        void addCaras(const vector<int> &c);
        vector <int> getCaras();
        void dibujar1(char tipo);
        void dibujar2(char tipo,float R,float G,float B);
        void desplazar(float desplazamiento,int x,int y,int z);
        void invertir(int x, int y, int z);
        void invertirCaras();
        void invertirVertices();

    private:
        void dibujar_ajedrez(float R,float G,float B);
        void dibujarMultiModo();

};
#endif
