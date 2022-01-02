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
public:
    Highway(int x, int y, int w, int t):y(y), x(x), dis(14-w*2){
        color = 7;
        timer = rand()%3+5;
        curTime = timer;
        status = true;
        timepass = 0.3;
        if (t == 0) {
            for (int i = 3; i<200;){
                lst.push_back(new Bicycle(i, y+2, x==-1));
                i += lst.back()->getWidth() + dis;
            }
        } else if (t == 1) {
            for (int i = 3; i<200;){
                lst.push_back(new Car(i, y+2, x==-1));
                i += lst.back()->getWidth() + dis;
            }
        } else if (t == 2) {
            for (int i = 3; i<200;){
                lst.push_back(new Cow(i, y+2, x==-1));
                i += lst.back()->getWidth() + dis;
            }
        }
        isUp = true;
        isImp = true;
    }
    void draw(windowCanvas &windowCanvas);
    void update(double t);
    bool isUpdate();
    void isImpact(Object*& u);
    bool checkImpact(Object*& u);
};


#endif // _Highway_
