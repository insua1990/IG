#include "objetorevolucion.h"

ObjetoRevolucion::ObjetoRevolucion(){
}

ObjetoRevolucion::ObjetoRevolucion(Ply *ply){
    vertices = ply->getVertices();
    caras = ply->getCaras();
}

ObjetoRevolucion::ObjetoRevolucion(Ply *ply,float alpha,float beta,int divisiones,int x,int y,int z){
    vertices = ply->getVertices();
    caras = ply->getCaras();
    this->revolucionar(alpha,beta,divisiones,x,y,z,true);
}

ObjetoRevolucion::ObjetoRevolucion(vector <float> perfil,vector <int> c,float alpha,float beta,int divisiones,int x,int y,int z){
    vertices = perfil;
    caras = c;
    this->revolucionar(alpha,beta,divisiones,x,y,z,true);
}

void ObjetoRevolucion::revolucionar(float alpha,float beta,int divisiones,int x,int y,int z,bool cerrar){

    // Limpiamos el vector de caras
    caras.clear();

    // Nos aseguramos de que beta es mayor que alpha
    while(alpha>beta) beta+=360;

    // Saber cuantas tapas tenemos y reorganizar el vector en caso de estar al revés.

    bool tapa_inf=false,tapa_sup=false;

    if(x == 1 && y == 0 && z == 0){

        if(vertices[0]>vertices[vertices.size()-3]) this->invertirVertices();
        if(vertices[1] == 0 && vertices[2] == 0) tapa_inf = true;
        else{
            if(cerrar){
                float f = vertices[0];
                this->invertirVertices();
                vertices.push_back(f);vertices.push_back(0);vertices.push_back(0);
                this->invertirVertices();
                tapa_inf = true;
            }
        }
        if(vertices[vertices.size()-2] == 0 && vertices[vertices.size()-1] == 0) tapa_sup=true;
        else{
            if(cerrar){
                float f = vertices[vertices.size()-3];
                vertices.push_back(f);vertices.push_back(0);vertices.push_back(0);
                tapa_sup=true;
            }
        }

    }else if(x == 0 && y == 1 && z == 0){

        if(vertices[1]>vertices[vertices.size()-2]) this->invertirVertices();
        if(vertices[0] == 0 && vertices[2] == 0) tapa_inf = true;
        else{
            if(cerrar){
                float f = vertices[1];
                this->invertirVertices();
                vertices.push_back(0);vertices.push_back(f);vertices.push_back(0);
                this->invertirVertices();
                tapa_inf = true;
            }
        }
        if(vertices[vertices.size()-3] == 0 && vertices[vertices.size()-1] == 0) tapa_sup=true;
        else{
            if(cerrar){
                float f = vertices[vertices.size()-2];
                vertices.push_back(0);vertices.push_back(f);vertices.push_back(0);
                tapa_sup=true;
            }
        }


    }else if(x == 0 && y == 0 && z == 1){

        if(vertices[2]>vertices[vertices.size()-1]) this->invertirVertices();
        if(vertices[1] == 0 && vertices[0] == 0) tapa_inf = true;
        else{
            if(cerrar){
                float f = vertices[2];
                this->invertirVertices();
                vertices.push_back(0);vertices.push_back(0);vertices.push_back(f);
                this->invertirVertices();
                tapa_inf = true;
            }
        }
        if(vertices[vertices.size()-2] == 0 && vertices[vertices.size()-3] == 0) tapa_sup=true;
        else{
            if(cerrar){
                float f = vertices[vertices.size()-1];
                vertices.push_back(0);vertices.push_back(0);vertices.push_back(f);
                tapa_sup=true;
            }
        }

    }
    // Extraemos los vertices de las tapas y los añadimos después de rotar para no repetir

    vector <float> aux;

    if(tapa_inf){
        aux.push_back(vertices[0]);
        aux.push_back(vertices[1]);
        aux.push_back(vertices[2]);
        vertices.erase(vertices.begin());
        vertices.erase(vertices.begin());
        vertices.erase(vertices.begin());
    }
    if(tapa_sup){
        aux.push_back(vertices[vertices.size()-3]);
        aux.push_back(vertices[vertices.size()-2]);
        aux.push_back(vertices[vertices.size()-1]);
        vertices.erase(vertices.begin()+vertices.size()-1);
        vertices.erase(vertices.begin()+vertices.size()-1);
        vertices.erase(vertices.begin()+vertices.size()-1);
    }

    // Calculos previos a la rotación

    const int tam_perfil = vertices.size()/3;

    //************** LLAMADA A ROTAR EN EL EJE CORRESPONDIENTE ******************
    this->rotar(alpha,beta,divisiones,x,y,z);


    // coloco los vertices al final
    for(int i = 0;i< aux.size();i++ ){
        vertices.push_back(aux[i]);
    }


    // creamos el vector de caras
    if(beta-alpha != 360)divisiones++;
    for(int div = 0; div < divisiones-1; div++){
        for(int i = 0; i < tam_perfil -1; i++){
            caras.push_back((div*tam_perfil+i+1));
            caras.push_back((div*tam_perfil+i));
            caras.push_back(((div+1)*tam_perfil+i));

            caras.push_back(((div+1)*tam_perfil+i));
            caras.push_back(((div+1)*tam_perfil+i+1));
            caras.push_back((div*tam_perfil+i+1));
        }
    }
    if(beta-alpha != 360)divisiones--;
    // la ultima vuelta
    if(beta-alpha == 360){
        for(int i=0;i<tam_perfil-1;i++){
            caras.push_back((divisiones-1)*tam_perfil+i+1);
            caras.push_back((divisiones-1)*tam_perfil+i);
            caras.push_back(i);

            caras.push_back(i);
            caras.push_back(i+1);
            caras.push_back((divisiones-1)*tam_perfil+i+1);
        }
    }

     //ahora creo las tapas
    if(tapa_inf || tapa_sup){
        if(beta-alpha != 360) divisiones++;
        int modulo= divisiones*tam_perfil;
        int limite = divisiones;
        if(beta-alpha != 360) limite--;
        if(tapa_inf && !tapa_sup){
            for(int div = 0;div<limite;div++){
                caras.push_back((divisiones*tam_perfil));caras.push_back(((div+1)*tam_perfil)%modulo);caras.push_back((div*tam_perfil)%modulo);
            }
        }
        else if(tapa_sup && !tapa_inf){
            for(int div = 0;div<limite;div++){
                caras.push_back(((div+1)*tam_perfil-1)%modulo);caras.push_back(((div+2)*tam_perfil-1)%modulo);caras.push_back((divisiones*tam_perfil));
            }
        }else if(tapa_sup && tapa_inf){
            for(int div = 0;div<limite;div++){
                caras.push_back((divisiones*tam_perfil));caras.push_back(((div+1)*tam_perfil)%modulo);caras.push_back((div*tam_perfil)%modulo);

            }
            for(int div = 0;div<limite;div++){
                caras.push_back(((div+1)*tam_perfil-1)%modulo);caras.push_back(((div+2)*tam_perfil-1)%modulo);caras.push_back((divisiones*tam_perfil)+1);
            }
        }
    }

}


void ObjetoRevolucion::rotar(float alpha,float beta,int divisiones,int x,int y,int z){

    const int tam_perfil = vertices.size()/3;
    float grados_rotar_final = alpha*PI/180.0;
    float grados_reales = (beta - alpha)*PI/180.0;
    float grados_por_div = grados_reales/divisiones;

    float xx,yy,zz;
    float coseno = cos(grados_por_div);
    float seno = sin(grados_por_div);
    float coseno_alpha = cos((alpha)*PI/180.0);
    float seno_alpha = sin((alpha)*PI/180.0);

    if(x==1){
        // Rotamos hasta beta-alpha

        if(beta-alpha == 360) divisiones--;
        for(int div = 0;div<divisiones;div++){
            for(int k = 0;k< 3*tam_perfil;k+=3){
                    xx = vertices[div*tam_perfil*3+k];
                    yy = (coseno*vertices[div*tam_perfil*3+k+1]) - (seno*vertices[div*tam_perfil*3+k+2]);
                    zz = (coseno*vertices[div*tam_perfil*3+k+2]) + (seno*vertices[div*tam_perfil*3+k+1]);
                    vertices.push_back(xx);
                    vertices.push_back(yy);
                    vertices.push_back(zz);
            }
        }
        if(beta-alpha == 360) divisiones++;

        //rotamos hasta alpha

        for(int i = 0;i<vertices.size();i+=3){
            yy=vertices[i+1];
            zz=vertices[i+2];
            vertices[i+1] = (coseno_alpha*yy) - (seno_alpha*zz);
            vertices[i+2] = (coseno_alpha*zz) + (seno_alpha*yy);
        }
    }else if(y==1){
        if(beta-alpha == 360) divisiones--;
        for(int div = 0;div<divisiones;div++){
            for(int k = 0;k< 3*tam_perfil;k+=3){
                    xx = (coseno*vertices[div*tam_perfil*3+k]) + (seno*vertices[div*tam_perfil*3+k+2]);
                    yy = vertices[div*tam_perfil*3+k+1];
                    zz = (coseno*vertices[div*tam_perfil*3+k+2]) - (seno*vertices[div*tam_perfil*3+k]);
                    vertices.push_back(xx);
                    vertices.push_back(yy);
                    vertices.push_back(zz);
            }
        }
        if(beta-alpha == 360) divisiones++;

        //rotamos hasta alpha

        for(int i = 0;i<vertices.size();i+=3){
            xx=vertices[i];
            zz=vertices[i+2];
            vertices[i] = (coseno_alpha*xx) + (seno_alpha*zz);
            vertices[i+2] = (coseno_alpha*zz) - (seno_alpha*xx);
        }
    }else if(z==1){
        if(beta-alpha == 360) divisiones--;
        for(int div = 0;div<divisiones;div++){
            for(int k = 0;k< 3*tam_perfil;k+=3){
                    xx = (coseno*vertices[div*tam_perfil*3+k]) - (seno*vertices[div*tam_perfil*3+k+1]);
                    yy = (coseno*vertices[div*tam_perfil*3+k+1]) + (seno*vertices[div*tam_perfil*3+k]);
                    zz = vertices[div*tam_perfil*3+k+2];

                    vertices.push_back(xx);
                    vertices.push_back(yy);
                    vertices.push_back(zz);
            }
        }
        if(beta-alpha == 360) divisiones++;

        //rotamos hasta alpha

        for(int i = 0;i<vertices.size();i+=3){
            xx=vertices[i];
            yy=vertices[i+1];
            vertices[i] = (coseno_alpha*xx) - (seno_alpha*yy);
            vertices[i+1] = (coseno_alpha*yy) + (seno_alpha*xx);
        }
    }
}
