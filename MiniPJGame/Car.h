#ifndef _Car_
#define _Car_

#include "Object.h"
#include <vector>

using namespace std;

class Car : public Object{
private:
    int color;
public:
    Car(int x, int y, bool isOn, bool isLeft): Object(x, y, 21, 4, isOn){
        sprite.push_back(vector<string>{"      .--------.     ",
                                        " ____/_____|___ \\___ ",
                                        "O    _   - |   _   ,*",
                                        " '--(_)-------(_)--' "
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

#endif // _Car_

