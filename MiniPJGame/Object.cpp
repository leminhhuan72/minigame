#include "Object.h"

void Object::moveTo(int x, int y){
    isUp = true;
    this->x += x;
    this->y += y;
}

int Object::getWidth(){
    return w;
}

bool Object::isUpdate(){
    if (isUp){
        isUp = false;
        return true;
    }
    return false;
}



int Object::getX(){
    return x;
}

char Object::revChar(char z){
    if (z == '/')
        z = '\\';
    else
    if (z == '\\')
        z = '/';
    else
    if (z == '(')
        z = ')';
    else
    if (z == ')')
        z = '(';
    return z;
}

void Object::makeBoundingBox(){
    int tmp = sprite.size();
    boundingBox.resize(tmp, vector<vector<bool> > (h, vector<bool> (w, false)));
    for (int z=0; z<tmp; ++z)
    for (int i=0; i<h; ++i)
    for (int j=0; j<w; ++j)
        if (sprite[z][i][j] != ' ')
            boundingBox[z][i][j] = true;
}
