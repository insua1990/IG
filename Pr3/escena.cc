#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"

using namespace std;

Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    pintaeje= true;
    figura = CUBO;
    tipo = TIPO_PUNTOS;
    axis = new Axis(5000);
    cubo = new Cubo(20);
    qcuatro = new Qcuatro(10);
    bender = new Bender();
    crear_solidos_barrido();
    leer_ply();
}

void Escena::leer_ply(){
    array_figuras.push_back(new Ply("./ply/big_dodge"));
    peon = new ObjetoRevolucion(new Ply("./ply/perfil" ),0,360,20,0,1,0);
}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

    glEnable(GL_CULL_FACE);

	this->change_projection();
	Width=UI_window_width/200;
	Height=UI_window_height/200;
	glViewport(0,0,UI_window_width,UI_window_height);

}

void Escena::crear_solidos_barrido(){

    vector <float> traza;
    vector <float> contorno;
    vector <int> caras_contorno;

    contorno.push_back(0);contorno.push_back(0);contorno.push_back(0);
    contorno.push_back(0);contorno.push_back(15);contorno.push_back(0);
    contorno.push_back(-15);contorno.push_back(15);contorno.push_back(0);
    contorno.push_back(-15);contorno.push_back(0);contorno.push_back(0);

    for(int k = -100;k<=100;k+=40){
        traza.push_back(0);traza.push_back(15);traza.push_back(k);
        traza.push_back(-15);traza.push_back(0);traza.push_back(k+10);
        traza.push_back(0);traza.push_back(-15);traza.push_back(k+20);
        traza.push_back(15);traza.push_back(0);traza.push_back(k+30);
    }


    caras_contorno.push_back(0);caras_contorno.push_back(2);caras_contorno.push_back(1);
    caras_contorno.push_back(0);caras_contorno.push_back(3);caras_contorno.push_back(2);

    snake3 = new ObjetoBarrido(contorno,caras_contorno,traza);

    contorno.clear();
    caras_contorno.clear();

    contorno.push_back(0);contorno.push_back(0);contorno.push_back(0);
    contorno.push_back(0);contorno.push_back(7.5);contorno.push_back(0);
    contorno.push_back(-7.5);contorno.push_back(0);contorno.push_back(0);

    caras_contorno.push_back(0);caras_contorno.push_back(2);caras_contorno.push_back(1);

    snake4 = new ObjetoBarrido(contorno,caras_contorno,traza);

    snake4->desplazar(50,1,0,0);

}
//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {
    switch (figura)
    {
        case CUBO:
            cubo->dibujar2(tipo,0,0,1);
            break;
        case BENDER:
            bender->dibujar(tipo);
            break;
        case BARRIDO:
            snake3->dibujar2(tipo,0,1,0);
            snake4->dibujar2(tipo,0,0,1);
            break;
        case QCUATRO:
            qcuatro->dibujar2(tipo,0,0,1);
            break;
        case BIG_DODGE:
            array_figuras[0]->dibujar2(tipo,0.5,0.5,0.5);
            break;
        case PEON:
            peon->dibujar2(tipo,0,0,0);
            break;
        default:
            break;

    }
}

void Escena::dibujar() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	axis->draw_axis();
	draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

	switch (Tecla1)
	{
	    case 'e':
            pintaeje = !pintaeje;
            axis->setPintar(pintaeje);
            return 0;
	    case '1':
            figura = CUBO;
            return 0;
        case '2':
            figura = QCUATRO;
            return 0;
        case '3':
            figura = BIG_DODGE;
            return 0;
        case '4':
            figura = PEON;
            return 0;
        case '5':
            figura = BARRIDO;
            return 0;
        case '6':
            figura = BENDER;
            return 0;


        case 'p':
            tipo = TIPO_PUNTOS;
            return 0;
        case 'l':
            tipo = TIPO_LINEAS;
            return 0;
        case 's':
            tipo = TIPO_SOLIDO;
            return 0;
        case 'a':
            tipo = TIPO_AJEDREZ;
            return 0;
        case 'm':
            tipo = TIPO_MULTIMODO;
            return 0;

        case 'Z':
            bender->giraCabezaIzq();
            return 0;
        case 'z':
            bender->giraCabezaDch();
            return 0;
        case 'V':
            bender->masVelocidadCabeza();
            return 0;
        case 'v':
            bender->menosVelocidadCabeza();
            return 0;
        case 'X':
            bender->giraBrazosDelante();
            return 0;
        case 'x':
            bender->giraBrazosDetras();
            return 0;
        case 'B':
            bender->masVelocidadBrazos();
            return 0;
        case 'b':
            bender->menosVelocidadBrazos();
            return 0;
        case 'C':
            bender->giraPiernaDelante();
            return 0;
        case 'c':
            bender->giraPiernaDetras();
            return 0;
        case 'N':
            bender->masVelocidadPierna();
            return 0;
        case 'n':
            bender->menosVelocidadPierna();
            return 0;

        case 'Q':
            return 1;
        default:
            return 0;
	}
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	//std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/100;
Height=newHeight/100;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}







