 #include "cubo.h"
 Cubo::Cubo(float lado){
    lado /=2;
    vertices.push_back(lado);vertices.push_back(-lado);vertices.push_back(lado);
    vertices.push_back(lado);vertices.push_back(lado);vertices.push_back(lado);
    vertices.push_back(lado);vertices.push_back(-lado);vertices.push_back(-lado);
    vertices.push_back(lado);vertices.push_back(lado);vertices.push_back(-lado);
    vertices.push_back(-lado);vertices.push_back(-lado);vertices.push_back(-lado);
    vertices.push_back(-lado);vertices.push_back(lado);vertices.push_back(-lado);
    vertices.push_back(-lado);vertices.push_back(-lado);vertices.push_back(lado);
    vertices.push_back(-lado);vertices.push_back(lado);vertices.push_back(lado);



    caras.push_back(0);caras.push_back(2);caras.push_back(3);
    caras.push_back(0);caras.push_back(3);caras.push_back(1);

    caras.push_back(2);caras.push_back(4);caras.push_back(5);
    caras.push_back(2);caras.push_back(5);caras.push_back(3);

    caras.push_back(4);caras.push_back(6);caras.push_back(7);
    caras.push_back(4);caras.push_back(7);caras.push_back(5);

    caras.push_back(6);caras.push_back(0);caras.push_back(1);
    caras.push_back(6);caras.push_back(1);caras.push_back(7);

    //tapas
    caras.push_back(7);caras.push_back(1);caras.push_back(3);
    caras.push_back(7);caras.push_back(3);caras.push_back(5);

    caras.push_back(4);caras.push_back(2);caras.push_back(0);
    caras.push_back(4);caras.push_back(0);caras.push_back(6);

 }
