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
    axis = new Axis(5000);
    figura = CUBO;
    cubo = new Cubo(20);
    cubo1 = new Cubo(20);
    tetra = new Tetraedro(10);
    tetra1 = new Tetraedro(10);
    tetra2 = new Tetraedro(10);
    tipo = TIPO_PUNTOS;
    transformaciones();

}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

    glEnable(GL_CULL_FACE);

	this->change_projection();
	Width=UI_window_width/100;
	Height=UI_window_height/100;
	glViewport(0,0,UI_window_width,UI_window_height);

}

void Escena::transformaciones(){
    tetra->invertir(0,1,0);
    tetra1->invertir(0,0,1);
    tetra1->desplazar(20.0,1,0,0);
    tetra2->invertir(1,0,0);
    tetra2->desplazar(-20.0,1,0,0);
}
//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {
    switch (figura)
    {
        case CUBO:
            cubo->dibujar2(tipo);
            break;
        case TETRAEDRO:
            tetra->dibujar2(tipo);
            break;
        case BARRIDO:
            tetra->dibujar2(tipo);
            tetra1->dibujar2(tipo);
            tetra2->dibujar2(tipo);
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

	switch (toupper(Tecla1))
	{
	    case 'E':
            pintaeje = !pintaeje;
            axis->setPintar(pintaeje);
            return 0;
	    case '1':
            figura = CUBO;
            return 0;
        case '2':
            figura = TETRAEDRO;
            return 0;
        case '3':
            figura = BARRIDO;
            return 0;


        case 'P':
            tipo = TIPO_PUNTOS;
            return 0;
        case 'L':
            tipo = TIPO_LINEAS;
            return 0;
        case 'S':
            tipo = TIPO_SOLIDO;
            return 0;
        case 'A':
            tipo = TIPO_AJEDREZ;
            return 0;
        case 'M':
            tipo = TIPO_MULTIMODO;
            return 0;
        case 'Q':
            return 1;
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







