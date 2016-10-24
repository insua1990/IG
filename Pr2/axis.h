#ifndef _AXIS_H
#define _AXIS_H

class Axis
{
    private :
        int asize;
        int rx,gx,bx;
        int ry,gy,by;
        int rz,gz,bz;
        bool pintar;

    public:
        Axis(int axis_size);
        Axis(int axis_size,int rx,int gx,int bx,int ry,int gy,int by,int rz,int gz,int bz);
        void draw_axis();
        void setPintar(bool pintado);

};
#endif
