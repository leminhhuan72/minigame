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
#include "SoundControl.h"

using namespace std;

class Game{
    double delta, timepass;
    int width, height, level;
    string playerName;
    bool turnOnMusic;
    windowCanvas windowCanvas;
    double speed;
public:
    Game():windowCanvas(){
        FixConsoleWindow();
        width = 145;
        height = 44;
        timepass = 0;
        level = 0;
        speed = 1;
        turnOnMusic = true;
    }
    void startGame();
    int showMenu1();
    void start();
    void loadGame();
    void startSetting();
    int showMenu2();
    int levelSetting();
    void musicSetting();
    bool showEnding();
    string getPlayerName();
    bool checkImpact(vector<Highway> &wayLst, Object*& u);
    vector<Highway> buildLevel(int u);
    void drawBox(); //
};

#endif // _Game_
