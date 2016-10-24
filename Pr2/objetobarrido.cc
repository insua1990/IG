#include "objetobarrido.h"

ObjetoBarrido::ObjetoBarrido(Ply *ply,vector <float> traza){
    this->init(ply->getVertices(),ply->getCaras(),traza);
}

ObjetoBarrido::ObjetoBarrido(vector <float> contorno,vector <int>caras_contorno,vector <float> traza){
    this->init(contorno,caras_contorno,traza);
}

void ObjetoBarrido::init(vector <float> contorno,vector <int>caras_contorno,vector <float> traza){
    // primer traslado para el ajuste
    float despX,despY,despZ;
    despX = traza[0] - contorno[0];
    despY = traza[1] - contorno[1];
    despZ = traza[2] - contorno[2];

    for(int i = 0; i<contorno.size();i+=3){
        contorno[i]+= despX;
        contorno[i+1]+= despY;
        contorno[i+2]+= despZ;
    }

    //creo vector vertices
    vertices = contorno;

    for(int i = 3; i<traza.size();i+=3){
        despX = traza[i] - traza[0];
        despY = traza[i+1] - traza[1];
        despZ = traza[i+2] - traza[2];
        for(int j = 0; j<contorno.size();j+=3){
            vertices.push_back(vertices[j]+despX);
            vertices.push_back(vertices[j+1]+despY);
            vertices.push_back(vertices[j+2]+despZ);
        }
    }

    // creo vector de caras
    caras = caras_contorno;
    int longtraza = traza.size();
    int tam = contorno.size()/3;
    int aux = 0;
    int m = longtraza/3 * tam;
    for(int i = 0; i< longtraza-3;i+=3){

        for(int j = 0; j< tam-1;j++){
            caras.push_back((j+aux)%m);caras.push_back((j+1+aux)%m);caras.push_back((j+tam+1+aux)%m);
            caras.push_back((tam+1+j+aux)%m);caras.push_back((tam+j+aux)%m);caras.push_back((j+aux)%m);
        }
        caras.push_back((tam+aux-1)%m);caras.push_back(aux%m);caras.push_back((tam+aux)%m);
        caras.push_back((tam+aux)%m);caras.push_back((tam+tam-1+aux)%m);caras.push_back((tam-1+aux)%m);
        aux+=tam;
    }

    //tapa
    vector <int> cara_aux;
    for(int i = 0; i< caras_contorno.size();i++){
        cara_aux.push_back(caras_contorno[i] + (((traza.size()/3)-1)*contorno.size()/3));
    }
    tam = cara_aux.size();
    for (int i = 0; i < tam; i++)
    {
        aux = cara_aux[i];
        cara_aux[i] = cara_aux[tam-1];
        cara_aux[tam-1] = aux;
        tam--;
    }
    for(int i = 0; i< caras_contorno.size();i++){
        caras.push_back(cara_aux[i]);
    }
}
