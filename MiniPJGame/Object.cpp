#include "Object.h"

void Object::moveTo(int x, int y){
    this->x += x;
    this->y += y;
}

bool Object::isImpact(const Object*& other){
    if (x < other->x){
        if (other->x-x < w)
            return false;
    }else{
        if (x-other->x < other->w)
            return false;
    }
    if (y < other->y){
        if (other->y-y < h)
            return false;
    }else{
        if (y-other->y < other->h)
            return false;
    }
    return true;
}
