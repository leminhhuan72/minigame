#ifndef _Highway_
#define _Highway_

#include "Object.h"
#include "Player.h"
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
    Highway(int x, int y, int w):y(y), x(x), dis(24-w*3){
        color = 7;
        timer = rand()%3+4;
        curTime = timer;
        status = true;
        timepass = 0.3;
        for (int i = 3; i<160; i+=dis)
            lst.push_back(new Player(i, y+2));
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
