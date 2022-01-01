#ifndef _Player_
#define _Player_

#include "Object.h"
#include <vector>

using namespace std;

class Player : public Object{
private:
    int color;
public:
    Player(int x, int y): Object(x, y, 5, 4){
        sprite.push_back(vector<string>{" ___ ",
                                        "(._.)",
                                        " <|> ",
                                        "_/ \\_"
                                        });
        cur = 0;
        color = 8;
        makeBoundingBox();
    }
    void draw(windowCanvas &windowCanvas);
    void moveTo(int x, int y);
    void playImpactSound(){};
};

#endif // _Player_
