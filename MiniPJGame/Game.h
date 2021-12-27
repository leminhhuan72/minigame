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
        FixConsoleWindow();
        width = 145;
        height = 44;
        timepass = 0;
        level = 0;
    }
    void startGame();
    int showMenu();
    void start();
    void loadGame();
    void setting();
    void showEnding();
    string getPlayerName();
    bool checkImpact(vector<Highway> &wayLst, Object*& u);
    vector<Highway> buildLevel(int u);
};

#endif // _Game_
