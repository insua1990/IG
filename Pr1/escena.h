
#ifndef _ESCENA_H
#define _ESCENA_H
#include "axis.h"
#include "objeto3d.h"
#include "cubo.h"
#include "tetraedro.h"
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
Cubo *cubo,*cubo1;
Tetraedro *tetra,*tetra1,*tetra2 ;

private:
	void clear_window();
	void draw_objects();

//Transformación de cámara
	void change_projection();
	void change_observer();
	void transformaciones();

public:
    const static int CUBO = 0;
    const static int TETRAEDRO = 1;
    const static int BARRIDO = 2;

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
