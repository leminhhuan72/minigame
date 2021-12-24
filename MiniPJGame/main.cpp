#include <iostream>
#include "Game.h"
#include <ctime>

using namespace std;

int main(){
    srand(time(nullptr));
    Game newGame;
    newGame.startGame();
    return 0;
}
