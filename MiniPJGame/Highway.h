#ifndef _Highway_
#define _Highway_

#include "Object.h"
#include "Player.h"
#include "Dino.h"
#include "Car.h"
#include "Owl.h"
#include "Cow.h"
#include "Truck.h"
#include "Bicycle.h"
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

class Highway{
private:
    vector<Object* > lst;
    int y, x; // y position, x = direct 1, -1
    int color, dis;
    bool isUp;
    double timer, timepass, curTime;
    bool status; // true - green, false - red
    bool isImp;
    bool onMic;
    Object* createObject(int x, int y, bool isOn, bool isLeft, int c) {
        if (c == 0) {
            return new Bicycle(x, y, isOn, isLeft);
        } else if (c == 1) {
            return new Car(x, y, isOn, isLeft);
        } else if (c == 2) {
            return new Cow(x, y, isOn, isLeft);
        }
        /// else if (c == 3)
        return new Dino(x, y, isOn, isLeft);
    }
public:
    Highway(int x, int y, bool isOn, int w, int c):y(y), x(x), dis(14-w*2){
        color = 7;
        timer = rand()%3+5;
        curTime = timer;
        status = true;
        timepass = 0.3;
        for (int i = 3; i<200;){
            lst.push_back(createObject(i, y+2, isOn, x==-1, c));
            i += lst.back()->getWidth() + dis;
        }
        isUp = true;
        onMic = isOn;
        isImp = true;
    }
    void draw(windowCanvas &windowCanvas);
    void update(double t);
    bool isUpdate();
    void isImpact(Object*& u);
    bool checkImpact(Object*& u);
};


#endif // _Highway_
