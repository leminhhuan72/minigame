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
    void draw();
    void moveTo(int x, int y){
        Object::moveTo(x, y);
        cur = (cur+1)%(int(sprite.size()));
    }
};

#endif // _Player_
