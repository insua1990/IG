#include <GL/gl.h>
#include <GL/glut.h>
#include "axis.h"

Axis::Axis(int axis_size){
     asize = axis_size;
     rx = 1;  gx = 0;  bx = 0;
     ry = 0;  gy = 1;  by = 0;
     rz = 0;  gz = 0;  bz = 1;
     pintar = true;
}

Axis::Axis(int axis_size,int rx,int gx,int bx,int ry,int gy,int by,int rz,int gz,int bz){
     asize = axis_size;
     rx = rx;  gx = gx;  bx = bx;
     ry = ry;  gy = gy;  by = by;
     rz = rz;  gz = gz;  bz = bz;
     pintar = true;
}

void Axis::setPintar(bool pintado){
    pintar = pintado;
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//*************************************************************************
void Axis::draw_axis(){
    if(pintar){
        glBegin(GL_LINES);
        // eje X, color rojo
        glColor3f( rx, gx, bx);
        glVertex3f(-asize,0,0);
        glVertex3f(asize,0,0);
        // eje Y, color verde
        glColor3f( ry, gy, by);
        glVertex3f(0,-asize,0);
        glVertex3f(0,asize,0);
        // eje Z, color azul
        glColor3f( rz, gz, bz);
        glVertex3f(0,0,-asize);
        glVertex3f(0,0,asize);
        glEnd();
    }
}
