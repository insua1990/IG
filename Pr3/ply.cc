
#include "ply.h"
Ply::Ply(char * filename){
    _file_ply::read(filename,vertices,caras);

}
