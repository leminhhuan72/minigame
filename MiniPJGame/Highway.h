#ifndef _Highway_
#define _Highway_

#include "Object.h"
#include "Player.h"
#include <vector>
#include <ctime>

using namespace std;

class Highway{
private:
    vector<Object* > lst;
    int y, x; // y position, x = direct 1, -1
    int color;
    double timer, timepass;
    bool status; // true - green, false - red
public:
    Highway(int x, int y):y(y), x(x){
        color = 16;
        timer = 7;
        status = true;
        timepass = 0.3;
        lst.push_back(new Player(140, y+2));
    }
    void draw();
    void update(double t);
};


#endif // _Highway_
