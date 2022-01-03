#include "Car.h"

void Car::draw(windowCanvas &windowCanvas){
    for (int i=0; i<h; ++i){
        windowCanvas.draw(x, y+i, sprite[cur][i], color);
    }
    ++cur;
    cur%=int(sprite.size());
}
void Car::playImpactSound(){
    if (isOn) {
        SoundControl* soundControl = SoundControl::GetInstance();
        soundControl->playSound("Sound//car_die.wav");
    }
}


