#ifndef _OBJETOREVOLUCION_H
#define _OBJETOREVOLUCION_H
#include "objeto3d.h"
#include "ply.h"
#include <math.h>
class ObjetoRevolucion:public Objeto3D{
public:
    static const float PI = 3.141592654;
    ObjetoRevolucion();
    ObjetoRevolucion(Ply *ply);
    ObjetoRevolucion(Ply * ply,float alpha,float beta,int divisiones,int x,int y,int z);
    ObjetoRevolucion(vector <float> perfil,vector <int> c,float alpha,float beta,int divisiones,int x,int y,int z);
    void revolucionar(float alpha,float beta,int divisiones,int x,int y,int z,bool cerrar);
private:
    void rotar(float alpha,float beta,int divisiones,int x,int y,int z);

};

#endif
