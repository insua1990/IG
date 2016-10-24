#include "qcuatro.h"

Qcuatro::Qcuatro(float lado){
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

    this->invertirCaras();

    vertices.push_back(lado+5);vertices.push_back(-lado-5);vertices.push_back(lado+5);
    vertices.push_back(lado+5);vertices.push_back(lado+5);vertices.push_back(lado+5);
    vertices.push_back(lado+5);vertices.push_back(-lado-5);vertices.push_back(-lado-5);
    vertices.push_back(lado+5);vertices.push_back(lado+5);vertices.push_back(-lado-5);
    vertices.push_back(-lado-5);vertices.push_back(-lado-5);vertices.push_back(-lado-5);
    vertices.push_back(-lado-5);vertices.push_back(lado+5);vertices.push_back(-lado-5);
    vertices.push_back(-lado-5);vertices.push_back(-lado-5);vertices.push_back(lado+5);
    vertices.push_back(-lado-5);vertices.push_back(lado+5);vertices.push_back(lado+5);


    caras.push_back(8);caras.push_back(10);caras.push_back(2);
    caras.push_back(2);caras.push_back(0);caras.push_back(8);
    caras.push_back(10);caras.push_back(11);caras.push_back(3);
    caras.push_back(3);caras.push_back(2);caras.push_back(10);
    caras.push_back(11);caras.push_back(9);caras.push_back(1);
    caras.push_back(1);caras.push_back(3);caras.push_back(11);
    caras.push_back(9);caras.push_back(8);caras.push_back(0);
    caras.push_back(0);caras.push_back(1);caras.push_back(9);

    caras.push_back(10);caras.push_back(12);caras.push_back(4);
    caras.push_back(4);caras.push_back(2);caras.push_back(10);
    caras.push_back(12);caras.push_back(13);caras.push_back(5);
    caras.push_back(5);caras.push_back(4);caras.push_back(12);
    caras.push_back(13);caras.push_back(11);caras.push_back(3);
    caras.push_back(3);caras.push_back(5);caras.push_back(13);
    caras.push_back(11);caras.push_back(10);caras.push_back(2);
    caras.push_back(2);caras.push_back(3);caras.push_back(11);

    caras.push_back(12);caras.push_back(14);caras.push_back(6);
    caras.push_back(6);caras.push_back(4);caras.push_back(12);
    caras.push_back(14);caras.push_back(15);caras.push_back(7);
    caras.push_back(7);caras.push_back(6);caras.push_back(14);
    caras.push_back(15);caras.push_back(13);caras.push_back(5);
    caras.push_back(5);caras.push_back(7);caras.push_back(15);
    caras.push_back(13);caras.push_back(12);caras.push_back(4);
    caras.push_back(4);caras.push_back(5);caras.push_back(13);

    caras.push_back(14);caras.push_back(8);caras.push_back(0);
    caras.push_back(0);caras.push_back(6);caras.push_back(14);
    caras.push_back(8);caras.push_back(9);caras.push_back(1);
    caras.push_back(1);caras.push_back(0);caras.push_back(8);
    caras.push_back(9);caras.push_back(15);caras.push_back(7);
    caras.push_back(7);caras.push_back(1);caras.push_back(9);
    caras.push_back(15);caras.push_back(14);caras.push_back(6);
    caras.push_back(6);caras.push_back(7);caras.push_back(15);

    caras.push_back(15);caras.push_back(9);caras.push_back(1);
    caras.push_back(1);caras.push_back(7);caras.push_back(15);
    caras.push_back(9);caras.push_back(11);caras.push_back(3);
    caras.push_back(3);caras.push_back(1);caras.push_back(9);
    caras.push_back(11);caras.push_back(13);caras.push_back(5);
    caras.push_back(5);caras.push_back(3);caras.push_back(11);
    caras.push_back(13);caras.push_back(15);caras.push_back(7);
    caras.push_back(7);caras.push_back(5);caras.push_back(13);

    caras.push_back(12);caras.push_back(10);caras.push_back(2);
    caras.push_back(2);caras.push_back(4);caras.push_back(12);
    caras.push_back(10);caras.push_back(8);caras.push_back(0);
    caras.push_back(0);caras.push_back(2);caras.push_back(10);
    caras.push_back(8);caras.push_back(14);caras.push_back(6);
    caras.push_back(6);caras.push_back(0);caras.push_back(8);
    caras.push_back(14);caras.push_back(12);caras.push_back(4);
    caras.push_back(4);caras.push_back(6);caras.push_back(14);




}
