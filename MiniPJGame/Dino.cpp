#include "Dino.h"

void Dino::draw(windowCanvas &windowCanvas){
    for (int i=0; i<h; ++i){
        windowCanvas.draw(x, y+i, sprite[cur][i], color);
    }
    ++cur;
    cur%=int(sprite.size());
}

void Dino::playImpactSound(){
    SoundControl* soundControl = SoundControl::GetInstance();
    soundControl->playSound("Sound//dinosaur_die.wav");
}
