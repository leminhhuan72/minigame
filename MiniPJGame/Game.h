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
    int width, height, level;
    string playerName;
    windowCanvas windowCanvas;
public:
    Game():windowCanvas(){
        width = 145;
        height = 44;
        timepass = 0;
        level = 0;
        FixConsoleWindow();
//        clearScreen(1, 1, width, height);
    }
    void startGame();
    int showMenu();
    void start();
    void loadGame();
    void setting();
    bool showEnding();
    string getPlayerName();
    bool checkImpact(vector<Highway> &wayLst, Object*& u);
    vector<Highway> buildLevel(int u);
    void drawBox(); //
};

#endif // _Game_
