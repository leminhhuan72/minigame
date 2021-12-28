#include "SoundControl.h"

void SoundControl::playBackGround(string s){
    if (s==curBackGround) return;
    if (isPlaySound)
        PlaySound(s.c_str(), NULL, SND_ASYNC | SND_LOOP);
    curBackGround = s;
}
