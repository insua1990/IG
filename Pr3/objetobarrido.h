#ifndef _OBJETOBARRIDO_H
#define _OBJETOBARRIDO_H
#include "objeto3d.h"
#include "ply.h"
class ObjetoBarrido: public Objeto3D{
public:
    ObjetoBarrido(Ply *ply,vector <float> traza);
    ObjetoBarrido(vector <float> contorno,vector <int>caras_contorno,vector <float> traza);
private:
    void init(vector <float> contorno,vector <int>caras_contorno,vector <float> traza);
};


#endif
