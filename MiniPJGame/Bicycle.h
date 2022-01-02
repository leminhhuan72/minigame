#ifndef _Bicycle_
#define _Bicycle_

#include "Object.h"
#include <vector>

using namespace std;

class Bicycle : public Object{
private:
    int color;
public:
    Bicycle(int x, int y, bool isLeft): Object(x, y, 7, 4){
        sprite.push_back(vector<string>{"   O   ",
                                        "  /\\,  ",
                                        " -|~(*)",
                                        "(*)    "
                                });
        if (isLeft){
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
};

#endif // _Bicycle_

