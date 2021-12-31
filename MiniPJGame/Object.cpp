#include "Object.h"

void Object::moveTo(int x, int y){
    isUp = true;
    this->x += x;
    this->y += y;
}

bool Object::isImpact(Object*& other){
////    cout << x << ' ' << y << endl;
//    return (isImpactX(other->x) || other->isImpactX(x)) && (isImpactY(other->y) || other->isImpactY(y));
    int x1 = max(x, other->x), y1 = max(y, other->y);
    int x2 = min(x+w, other->x+other->w), y2 = min(y+h, other->y+other->h);
    if (x1 > x2 || y1 > y2) return false;
    for (int i=y1; i<y2; ++i)
    for (int j=x1; j<x2; ++j){
        if (boundingBox[cur][i-y][j-x] && other->boundingBox[other->cur][i-other->y][j-other->x]){
            playImpactSound();
            return true;
        }
    }
    return false;
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

bool Object::isImpactX(int x){
    return (this->x <= x && x <= this->x + this->w);
}
bool Object::isImpactY(int y){
    return (this->y <= y && y <= this->y + this->h);
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
