#ifndef _Game_
#define _Game_

#include <ctime>
#include "Object.h"
#include "Player.h"
#include "windowControl.h"
#include "Highway.h"
#include <thread>
#include <vector>
#include <conio.h>
#include <iostream>

using namespace std;

class Game{
    double delta, timepass;
    int width, height;
public:
    Game(){
        width = 140;
        height = 40;
        delta = CLOCKS_PER_SEC/1;
        timepass = 0;
        FixConsoleWindow();
        clearScreen();
    }
    void startGame();
    int showMenu();
    void start();
    void loadGame();
    void setting();
};

#endif // _Game_
