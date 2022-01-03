#ifndef _Owl_
#define _Owl_

#include "Object.h"
#include <vector>

using namespace std;

class Owl : public Object{
private:
    int color;
public:
    Owl(int x, int y, bool isOn, bool isLeft): Object(x, y, 7, 4, isOn){
        sprite.push_back(vector<string>{" /\\_/\\ ",
                                        "((@v@))",
                                        "():::()",
                                        " VV-VV "
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

#endif // _Owl_


