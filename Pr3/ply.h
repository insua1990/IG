#ifndef _PLY_H
#define _PLY_H
#include "file_ply_stl.hpp"
#include "objeto3d.h"

class Ply:public Objeto3D{
public:
    Ply(char *filename);
};
#endif
