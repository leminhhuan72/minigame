#ifndef _Object_
#define _Object_

#include "windowControl.h"
#include <algorithm>

using namespace std;

class Object{
protected:
    int x, y, w, h;
    bool isUp;
public:
    Object(int x, int y, int w, int h):x(x), y(y), w(w), h(h), isUp(true){}
    virtual ~Object(){}
    virtual void moveTo(int x, int y);
    bool isImpact(Object*& other);
    bool isUpdate();
    bool isImpactX(int x);
    bool isImpactY(int y);
    char revChar(char z);
    int getWidth();
    int getX();
    virtual void draw(windowCanvas &windowCanvas) = 0;
};

#endif // _Object_
