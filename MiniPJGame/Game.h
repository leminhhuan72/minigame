#ifndef _Game_
#define _Game_

#include <ctime>
#include <fstream>
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

struct dataSave{
    string name;
    int level;
    double speed;
    dataSave(string n = "", int lv = 0, double spd = 0): name(n), level(lv), speed(spd){}
};

class Game{
    double delta, timepass;
    int width, height, level;
    string playerName;
    bool turnOnMusic;
    windowCanvas windowCanvas;
    double speed;
    vector<dataSave > dataLst; // name, level
public:
    Game():windowCanvas(){
        loadData();
        FixConsoleWindow();
        width = 145;
        height = 44;
        timepass = 0;
        level = 0;
        speed = 1;
        turnOnMusic = true;
    }
    void startGame();
    void updatePlayerData();
    int showMenu1();
    void start();
    void loadData();
    int loadGame();
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
