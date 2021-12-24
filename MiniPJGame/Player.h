#ifndef _Player_
#define _Player_

#include "Object.h"
#include <vector>

using namespace std;

class Player : public Object{
private:
    vector<vector<string> > sprite;
    int cur;
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
    }
    void draw(windowCanvas &windowCanvas);
    void moveTo(int x, int y){
        if (this->x + x >=1 && this->x + this->w + x < 144 &&
                this->y + y >=1 && this->y + this->h + y < 43)
            Object::moveTo(x, y);
        cur = (cur+1)%(int(sprite.size()));
    }
};

#endif // _Player_
