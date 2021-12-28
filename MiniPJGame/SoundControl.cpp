#include "SoundControl.h"

void SoundControl::playBackGround(string s){
    if (s==curBackGround) return;
    if (isPlaySound)
        PlaySound(s.c_str(), NULL, SND_ASYNC | SND_LOOP);
    curBackGround = s;
}

void SoundControl::playBackGround1(){
    playBackGround("Sound//Background.wav");
}
void SoundControl::playBackGround2(){
    playBackGround("Sound//Background2.wav");
}
