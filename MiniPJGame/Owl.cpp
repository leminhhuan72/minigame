#include "Owl.h"

void Owl::draw(windowCanvas &windowCanvas){
    for (int i=0; i<h; ++i){
        windowCanvas.draw(x, y+i, sprite[cur][i], color);
    }
    ++cur;
    cur%=int(sprite.size());
}
void Owl::playImpactSound(){
    if (isOn) {
        SoundControl* soundControl = SoundControl::GetInstance();
        soundControl->playSound("Sound//bird_die.wav");
    }
}




