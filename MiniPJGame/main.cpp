#include <iostream>
#include "Game.h"
#include <ctime>

using namespace std;

SoundControl* SoundControl::soundControl = nullptr;

int main(){
    srand(time(nullptr));
    Game newGame;
    newGame.startGame();
    return 0;
}
