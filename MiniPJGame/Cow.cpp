#include "Cow.h"

void Cow::draw(windowCanvas &windowCanvas){
    for (int i=0; i<h; ++i){
        windowCanvas.draw(x, y+i, sprite[cur][i], color);
    }
    ++cur;
    cur%=int(sprite.size());
}

void Cow::playImpactSound(){
    SoundControl* soundControl = SoundControl::GetInstance();
    soundControl->playSound("Sound//cow_die.wav");
}
