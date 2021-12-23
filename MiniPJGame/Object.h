#ifndef _Object_
#define _Object_

#include "windowControl.h"

using namespace std;

class Object{
protected:
    int x, y, w, h;
public:
    Object(int x, int y, int w, int h):x(x), y(y), w(w), h(h){}
    void moveTo(int x, int y);
    bool isImpact(const Object*& other);
    virtual void draw() = 0;
};

#endif // _Object_
