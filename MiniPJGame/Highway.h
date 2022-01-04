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
    double mSpeed;
    int typeObstacle;
public:
    Highway(int x, int y, int w, double s):y(y), x(x), dis(14-w*2){
        typeObstacle = rand()%5;
        color = 7;
        timer = rand()%3+5;
        curTime = timer;
        status = true;
        for (int i = 3; i<200;){
            lst.push_back(createObject(i));
            i += lst.back()->getWidth() + dis;
        }
        isUp = true;
        isImp = true;
        mSpeed = s;
        timepass = speedSetting(mSpeed);
    }
    void draw(windowCanvas &windowCanvas);
    void update(double t);
    bool isUpdate();
    void isImpact(Object*& u);
    bool checkImpact(Object*& u);

    Object* createObject(int i);
    double speedSetting(double t);
};


#endif // _Highway_
