#ifndef _Truck_
#define _Truck_

#include "Object.h"
#include <vector>

using namespace std;

class Truck : public Object{
private:
    int color;
public:
    Truck(int x, int y, bool isLeft): Object(x, y, 20, 4){
        sprite.push_back(vector<string>{"    __   __________ ",
                                        "  _//]|-|          |",
                                        " |____|-|__________|",
                                        " '--(_)-------(_)--'"
                                        });
        if (!isLeft){
            for (auto &u: sprite)
                for (auto &v: u){
                    reverse(v.begin(), v.end());
                    for (auto &z: v)
                        z = revChar(z);
                }
        }
        cur = 0;
        color = 8;
        makeBoundingBox();
    }
    void draw(windowCanvas &windowCanvas);
    void moveTo(int x, int y){
        Object::moveTo(x, y);
        cur = (cur+1)%(int(sprite.size()));
    }
    void playImpactSound();
};

#endif // _Truck_


