#include "Object.h"

void Object::moveTo(int x, int y){
    isUp = true;
    this->x += x;
    this->y += y;
}

bool Object::isImpact(Object*& other){
//    cout << x << ' ' << y << endl;
    return (isImpactX(other->x) || other->isImpactX(x)) && (isImpactY(other->y) || other->isImpactY(y));
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
