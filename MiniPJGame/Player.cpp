#include "Player.h"

void Player::draw(windowCanvas &windowCanvas){
    for (int i=0; i<h; ++i){
        windowCanvas.draw(x, y+i, sprite[cur][i], color);
    }
    ++cur;
    cur%=int(sprite.size());
}

void Player::moveTo(int x, int y){
    if (this->x + x >=1 && this->x + this->w + x < 144 &&
            this->y + y >=1 && this->y + this->h + y < 43)
        Object::moveTo(x, y);
    cur = (cur+1)%(int(sprite.size()));
}
