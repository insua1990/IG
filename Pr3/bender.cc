#include "bender.h"

Bender::Bender(){
    Semiesfera *s = new Semiesfera(0.75);
    pizq = new Pierna(new Ply("./ply/bender/leg"),s);
    pdch = new Pierna(new Ply("./ply/bender/leg"),s);
    cuerpo = new Cuerpo(new Ply("./ply/bender/body"),s,s);
    bizq = new Brazo(new Ply("./ply/bender/arm"),new Mano(new Ply("./ply/bender/hand"),new Dedo(new Ply("./ply/bender/finger"))));
    bdch = new Brazo(new Ply("./ply/bender/arm"),new Mano(new Ply("./ply/bender/hand"),new Dedo(new Ply("./ply/bender/finger"))));
    Frontal *f = new Frontal(new Ojo(0.335),new Ply("./ply/bender/f1"),new Ply("./ply/bender/f2"));
    ObjetoRevolucion *cuello = new ObjetoRevolucion(new Ply("./ply/bender/neck"));
    cuello->revolucionar(0,360,40,0,1,0,true);
    ObjetoRevolucion *nuca = new ObjetoRevolucion(new Ply("./ply/bender/teeth"));
    nuca->revolucionar(0,240,27,0,1,0,false);
    ObjetoRevolucion *sien = new ObjetoRevolucion(new Ply("./ply/bender/face"));
    sien->revolucionar(0,360,40,0,1,0,true);
    ObjetoRevolucion *antena = new ObjetoRevolucion(new Ply("./ply/bender/receiver"));
    antena->revolucionar(0,360,10,0,1,0,true);
    Dientes *dientes = new Dientes(new Ply("./ply/bender/teeth"));
    cabeza = new Cabeza(new Semiesfera(1.0),sien,nuca,dientes,cuello,f,antena);
    gradoC = 0;gradoB = 0;gradoP = 0;
    velocidadC = 0.50;velocidadB = 0.50;velocidadP = 0.50;
}

void Bender:: dibujar(char tipo){
glPushMatrix();
    glScalef(0.85,1,0.85);

    // CABEZA
    glPushMatrix();

        // GRADO LIBERTAD
        glRotatef(gradoC,0,1,0);
        cabeza->dibujar(tipo);

    glPopMatrix();



	// CUERPO
    cuerpo->dibujar(tipo);



    // BRAZOS
    glPushMatrix();

        // GRADO LIBERTAD
        glTranslatef(-1.8,-0.6,0.0);
        glRotatef(-gradoB,0.0,1.0,0.0);
        glTranslatef(+1.8,+0.6,0.0);

        glTranslatef(-1.8,-0.6,0.0);
        glRotatef(270,0.0,0.0,1.0);

        bdch->dibujar(tipo);
	glPopMatrix();


    glPushMatrix();

        // GRADO LIBERTAD
        glTranslatef(1.8,-0.6,0.0);
        glRotatef(gradoB,0.0,1.0,0.0);
        glTranslatef(-1.8,0.6,0.0);

        glTranslatef(1.8,-0.6,0.0);
        glRotatef(90,0.0,0.0,1.0);
        bizq->dibujar(tipo);

	glPopMatrix();



	// PIERNAS
    glPushMatrix();

        // GRADO LIBERTAD
        glTranslatef(0.8,-4.0,0.0);
        glRotatef(gradoP,1.0,0.0,0.0);
        glTranslatef(-0.8,4.0,0.0);

        glTranslatef(0.8,-4.0,0.0);
        pizq->dibujar(tipo);

	glPopMatrix();

	glPushMatrix();

	// GRADO LIBERTAD
        glTranslatef(0.8,-4.0,0.0);
        glRotatef(-gradoP,1.0,0.0,0.0);
        glTranslatef(-0.8,4.0,0.0);

        glTranslatef(-0.8,-4.0,0.0);
        pdch->dibujar(tipo);

	glPopMatrix();

glPopMatrix();
}

void Bender::giraCabezaDch(){
    gradoC-=velocidadC;
    if(gradoC < -90) gradoC = -90;
}

void Bender::giraCabezaIzq(){
    gradoC+=velocidadC;
    if(gradoC > 90) gradoC = 90;
}

void Bender::masVelocidadCabeza(){
    if(velocidadC<2) velocidadC+=0.05;
}

void Bender::menosVelocidadCabeza(){
    if(velocidadC>0.10) velocidadC-=0.05;
}

void Bender::giraBrazosDelante(){
    gradoB-=velocidadB;
    if(gradoB < -90) gradoB = -90;
}

void Bender::giraBrazosDetras(){
    gradoB+=velocidadB;
    if(gradoB > 10) gradoB = 10;
}

void Bender::masVelocidadBrazos(){
    if(velocidadB<2) velocidadB+=0.05;
}

void Bender::menosVelocidadBrazos(){
    if(velocidadB>0.10) velocidadB-=0.05;
}

void Bender::giraPiernaDelante(){
    gradoP+=velocidadP;
    if(gradoP > 45) gradoP = 45;
}

void Bender::giraPiernaDetras(){
    gradoP-=velocidadP;
    if(gradoP < -45) gradoP = -45;
}

void Bender::masVelocidadPierna(){
    if(velocidadP<2) velocidadP+=0.05;
}

void Bender::menosVelocidadPierna(){
    if(velocidadP>0.10) velocidadP-=0.05;
}
