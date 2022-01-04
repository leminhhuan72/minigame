#ifndef _Object_
#define _Object_

#include "windowControl.h"
#include <algorithm>

using namespace std;

class Object{
protected:
    int x, y, w, h;
    bool isUp;
    int color;
    vector<vector<vector<bool> > > boundingBox;
    vector<vector<string> > sprite;
    int cur;
public:
    Object(int x, int y, int w, int h):x(x), y(y), w(w), h(h), isUp(true), color(rand()%15 + 1){}
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
    virtual void playImpactSound() = 0;
    void makeBoundingBox();
};

#endif // _Object_
