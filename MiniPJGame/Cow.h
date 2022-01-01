#ifndef _Cow_
#define _Cow_

#include "Object.h"
#include <vector>

using namespace std;

class Cow : public Object{
private:
    int color;
public:
    Cow(int x, int y, bool isLeft): Object(x, y, 12, 4){
        sprite.push_back(vector<string>{"        (__)",
                                        "`\\------(oo)",
                                        "  ||    (__)",
                                        "  ||w--||   "
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

#endif // _Cow_

