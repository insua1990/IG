#include "tetraedro.h"

Tetraedro::Tetraedro(float x){
    vertices.push_back(0);
    vertices.push_back(-x);
    vertices.push_back(x);

    vertices.push_back(x);
    vertices.push_back(-x);
    vertices.push_back(-x);

    vertices.push_back(-x);
    vertices.push_back(-x);
    vertices.push_back(-x);

    vertices.push_back(0);
    vertices.push_back(x);
    vertices.push_back(0);

    caras.push_back(0);
    caras.push_back(1);
    caras.push_back(3);

    caras.push_back(1);
    caras.push_back(2);
    caras.push_back(3);

    caras.push_back(2);
    caras.push_back(0);
    caras.push_back(3);

    caras.push_back(2);
    caras.push_back(1);
    caras.push_back(0);
}
