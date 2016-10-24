#ifndef _ESCENA_H
#define _ESCENA_H
#include "axis.h"
#include "objeto3d.h"
#include "cubo.h"
#include "tetraedro.h"
#include "objetobarrido.h"
#include "qcuatro.h"
#include "ply.h"
#include "objetorevolucion.h"

#include "bender.h"

class Escena {
private:

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

// ejes
Axis *axis;
bool pintaeje;

// variable para el tipo de figura y el modo de visualizacion
int figura;
char tipo;

// figuras
Cubo *cubo;
ObjetoBarrido *snake3,*snake4;
Qcuatro *qcuatro;
ObjetoRevolucion *peon;
vector <Ply *> array_figuras;

//bender
Bender *bender;

private:
	void clear_window();
	void draw_objects();

//Transformación de cámara
	void change_projection();
	void change_observer();
	void crear_solidos_barrido();
	void leer_ply();

public:
    const static int CUBO = 1;
    const static int QCUATRO = 2;
    const static int BIG_DODGE = 3;
    const static int PEON = 4;
    const static int BARRIDO = 5;
    const static int BENDER = 6;


    const static char TIPO_PUNTOS = 'p';
    const static char TIPO_LINEAS = 'l';
    const static char TIPO_SOLIDO = 's';
    const static char TIPO_AJEDREZ = 'a';
    const static char TIPO_MULTIMODO = 'm';

    Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);

};
#endif
