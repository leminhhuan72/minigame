#include "Game.h"

void Game::startGame(){
    bool isRunning = true;
    SoundControl* soundControl = SoundControl::GetInstance();
    do{
        /// Sound;
        soundControl->playBackGround1();
        switch (showMenu1()){
        case 0:
            playerName = getPlayerName();
            updatePlayerData();
            start();
            break;
        case 1:
            if (loadGame()==-1)
                break;
            else
                start();
        case 2:
            startSetting();
            break;
        default:
            isRunning = false;
            break;
        }
    }while(isRunning);
}

int Game::showMenu1(){
    windowCanvas.resetLim();
    int cur = 0;
    for (int i=0;i<width+10;++i)
    for (int j=0;j<height;++j){
        if (i==0 || j==0 || i==width+9 || j==height-1){
            windowCanvas.draw(i, j, '*', 10);
        }else
            windowCanvas.draw(i, j, ' ', 7);
    }

    windowCanvas.drawScreen();
    vector<string> a = {"NEW  GAME", "LOAD GAME", "SETTING", "QUIT"};
    int startRow = height/2 -1 - int(a.size())/2, startCol;
    int tmp;
    int m = a.size();
    do{
        for (int i=0; i<m; ++i){
            startCol = width/2 + 5 -1 - int(a[i].size())/2;
            if (i == cur){
                windowCanvas.draw(startCol, startRow+i, a[i], 23);
            }else{
                windowCanvas.draw(startCol, startRow+i, a[i], 15);
            }
        }
        windowCanvas.drawScreen();
        tmp = getch();
        if (tmp == 80){
            cur = (cur+1)%m;
        }else
        if (tmp == 72){
            cur = (cur-1+m)%m;
        }else
        if (tmp == 13){
            return cur;
        }else
        if (tmp == 27){
            return m-1;
        }
    }while(true);
}

vector<Highway> Game::buildLevel(int u){
    vector<Highway> a;
    int lane = u/3 +1 ;
    int dis = u%3;
    for (int i=0;i<lane; ++i)
        a.emplace_back((i&1?1:-1), 8+i*7, dis, speed);
    return a;
}

bool Game::checkImpact(vector<Highway> &wayLst, Object*& u){
    for (auto &v: wayLst)
        if (v.checkImpact(u))
            return true;
    return false;
}

bool Game::showEnding(){
    windowCanvas.resetLim();
    for (int i=0;i<width+10;++i)
    for (int j=0;j<height;++j){
        if (i==0 || j==0 || i==width+9 || j==height-1){
            windowCanvas.draw(i, j, '*', 10);
        }else
            windowCanvas.draw(i, j, ' ', 7);
    }

    vector<string> a = {"Player: " + playerName, "Level: " + to_string(level+1), "Press any ESC to quit!", "Press Y to play again this level"};
    int startRow = height/2 -1 - int(a.size())/2, startCol;
    int m = a.size();
    for (int i=0; i<m; ++i){
        startCol = width/2 + 5 -1 - int(a[i].size())/2;
        windowCanvas.draw(startCol, startRow+i, a[i], 15);
    }
    windowCanvas.drawScreen();
//    int tmp;
//    do{
//        tmp = getch();
//    }while(tmp != 27 &&tmp!=121);   //check choice : esc or yes to replay this level
//    if(tmp==121)return true;
    return false;
}

string Game::getPlayerName(){
    string name;
    windowCanvas.resetLim();
    for (int i=0;i<width+10;++i)
    for (int j=0;j<height;++j){
        if (i==0 || j==0 || i==width+9 || j==height-1){
            windowCanvas.draw(i, j, '*', 10);
        }else
            windowCanvas.draw(i, j, ' ', 7);
    }
    int startRow = height/2 -1;
    windowCanvas.draw(20, startRow, "Enter your name (Enter to finish): ", 10);
    windowCanvas.drawScreen();
    int tmp;
    do{
        for (int i=0;i<width+10;++i)
        for (int j=0;j<height;++j){
            if (i==0 || j==0 || i==width+9 || j==height-1){
                windowCanvas.draw(i, j, '*', 10);
            }else
                windowCanvas.draw(i, j, ' ', 7);
        }
        windowCanvas.draw(20, startRow, "Enter your name (Enter to finish): ", 10);
        GotoXY(55+int(name.size()), startRow);
        tmp = getch();
        if (int(name.size())>10){

        }else
        if (tmp == 32){ // space
            // pass
        }else
        if (tmp == 13)
            break;
        else
        if (tmp == 8){
            if (!name.empty())
                name.pop_back();
        }else
            name.push_back(char(tmp));
        windowCanvas.draw(55, startRow, name, 13);
        windowCanvas.drawScreen();
    }while(true);
    return name;
}
void Game::drawBox(){
  for (int i=0;i<width;++i)
    for (int j=0;j<height;++j){
        if (i==0 || j==0 || i==width-1 || j==height-1){
            windowCanvas.draw(i, j, '*', 10);
        }
    }
}
void Game::start(){
    /// Sound;
    SoundControl* soundControl = SoundControl::GetInstance();
    soundControl->playBackGround2();
    windowCanvas.clearScreen();
    Object* p = new Player(70, 39);
    drawBox();

    bool isRunning = true;

    windowCanvas.drawScreen();
    windowCanvas.setLim(0,0, width, height);

    vector<Highway> wayLst = buildLevel(level);

    int tmp;
    timepass = 0;
    double timing = 0;
    bool isPause = false;
    auto updateGame = [&](){
        while(isRunning){
            if (isPause){
                showEnding();
                continue;
            }
            /// update level
            if (p->isImpactY(3)){
                soundControl->playSound("Sound//levelup.wav");
                ++level;
                wayLst.clear();
                wayLst = buildLevel(level);
                delete p;
                p = new Player(70, 39);
                soundControl->playBackGround2();
                updatePlayerData();
                timing = clock();
            }
            /// check impact
            if (checkImpact(wayLst, p)){
                isPause = true;
                soundControl->playSound("Sound//player_die.wav");
                continue;
            }
            for (int i=1;i<width-1;++i)
            for (int j=1;j<height-1;++j){
                windowCanvas.draw(i, j, ' ', 7);
            }
            double tmp = clock() - timing;
            timing = clock();
            for (auto &u: wayLst){
                u.update(tmp);
                u.isImpact(p);
                u.draw(windowCanvas);
            }
            p->draw(windowCanvas);

            for (int i=0;i<width;++i)
            for (int j=0;j<height;++j){
                if (i==0 || j==0 || i==width-1 || j==height-1){
                    windowCanvas.draw(i, j, '*', 10);
                }
            }
            windowCanvas.drawScreen();
        }
    };

    thread t1(updateGame);
    while(isRunning){
        tmp = getch();
//        cout << tmp << endl;
        if (isPause){
            if (tmp == 121){
                soundControl->playBackGround2();
                windowCanvas.clearScreen();
                windowCanvas.setLim(0,0, width, height);
                wayLst.clear();
                wayLst = buildLevel(level);
                delete p;
                p = new Player(70, 39);
                isPause = false;
            }else
            if (tmp == 27){
                isRunning = false;
                break;
            }
        }else
        if (tmp == 80){
            p->moveTo(0, 1);
        }else
        if (tmp == 72){
            p->moveTo(0, -1);
        }else
        if (tmp == 75){
            p->moveTo(-1, 0);
        }else
        if (tmp == 77){
            p->moveTo(1, 0);
        }
    }
    t1.join();
//    if(showEnding())start();
}

bool cmp(const dataSave &u, const dataSave &v){
    return u.level == v.level ? u.speed > v.speed : u.level > v.level;
}

int Game::loadGame(){
    sort(dataLst.begin(), dataLst.end(), cmp);
    windowCanvas.resetLim();
    for (int i=0;i<width+10;++i)
    for (int j=0;j<height;++j){
        if (i==0 || j==0 || i==width+9 || j==height-1){
            windowCanvas.draw(i, j, '*', 10);
        }else
            windowCanvas.draw(i, j, ' ', 7);
    }
    vector<string> a = {"+---------------------------+",
                        "|GAME          LEVEL   SPEED|",
                        "|---------------------------|",
                        "|                           |",
                        "|                           |",
                        "|                           |",
                        "|                           |",
                        "|                           |",
                        "|                           |",
                        "|                           |",
                        "+---------------------------+"};
    int startRow = height/2 -1 - int(a.size())/2, startCol;
    int m = a.size();
    int cur=0, n = dataLst.size(), l, r, tmp;
    l = 0, r = min(n, 7);
    do{
        for (int i=0; i<m; ++i){
            startCol = width/2 + 5 -1 - int(a[i].size())/2;
            windowCanvas.draw(startCol, startRow+i, a[i], 14);
        }

        while(cur<l||cur>=r){
            if (cur < l){
                --l, --r;
            }else{
                ++l, ++r;
            }
        }

        for (int i=0; i+l<r; ++i){
            string h=dataLst[i+l].name;
            while(int(h.size()) < 14)
                h.push_back(' ');
            h += to_string(dataLst[i+l].level+1);
            while(int(h.size()) < 22)
                h.push_back(' ');
            h += to_string(int(dataLst[i+l].speed));
            while(int(h.size()) < 27)
                h.push_back(' ');
            startCol = width/2 + 5 -1 - int(h.size())/2;
            if (i+l == cur)
                windowCanvas.draw(startCol, startRow+3+i, h, 236);
            else
                windowCanvas.draw(startCol, startRow+3+i, h, 12);
        }

        windowCanvas.drawScreen();

        tmp = getch();
        if (tmp == 80){
            if (n)
                cur = (cur+1)%n;
        }else
        if (tmp == 72){
            if (n)
                cur = (cur-1+n)%n;
        }else
        if (tmp == 13){
            break;
        }else
        if (tmp == 27){
            return -1;
        }

    }while(true);
    if (cur == n) return -1;
    playerName = dataLst[cur].name;
    level = dataLst[cur].level;
    speed = dataLst[cur].speed;
    return 1;
}

void Game::loadData(){
    ifstream fi;
    fi.open("Data//data.txt");
    int n = 0;
    fi >> n;
    dataLst.resize(n);
    for (int i=0; i<n; ++i)
        fi >> dataLst[i].name >> dataLst[i].level >> dataLst[i].speed;
    sort(dataLst.begin(), dataLst.end(), cmp);
    fi.close();
}

void Game::startSetting() {
    SoundControl* soundControl = SoundControl::GetInstance();
    /// Sound;
    soundControl->playBackGround1();
    int tmp = showMenu2();
    if (tmp == 0) {
        int tmp = levelSetting();
        if (tmp != 6) {
            speed = tmp;
        }
    } else if (tmp == 1) {
        musicSetting();
    }
}

int Game::showMenu2() {
    windowCanvas.resetLim();
    int cur = 0;
    for (int i=0;i<width+10;++i)
    for (int j=0;j<height;++j){
        if (i==0 || j==0 || i==width+9 || j==height-1){
            windowCanvas.draw(i, j, '*', 10);
        }else
            windowCanvas.draw(i, j, ' ', 7);
    }

    windowCanvas.drawScreen();
    vector<string> a = {"LEVEL", "MUSIC", "TURN BACK"};
    int startRow = height/2 -1 - int(a.size())/2, startCol;
    int tmp;
    int m = a.size();
    do{
        for (int i=0; i<m; ++i){
            startCol = width/2 + 5 -1 - int(a[i].size())/2;
            if (i == cur){
                windowCanvas.draw(startCol, startRow+i, a[i], 23);
            }else{
                windowCanvas.draw(startCol, startRow+i, a[i], 15);
            }
        }
        windowCanvas.drawScreen();
        tmp = getch();
        if (tmp == 80){
            cur = (cur+1)%m;
        }else
        if (tmp == 72){
            cur = (cur-1+m)%m;
        }else
        if (tmp == 13){
            return cur;
        }else
        if (tmp == 27){
            return m-1;
        }
    }while(true);
}

int Game::levelSetting(){
    windowCanvas.resetLim();
    int cur = 0;
    for (int i=0;i<width+10;++i)
    for (int j=0;j<height;++j){
        if (i==0 || j==0 || i==width+9 || j==height-1){
            windowCanvas.draw(i, j, '*', 10);
        }else
            windowCanvas.draw(i, j, ' ', 7);
    }

    windowCanvas.drawScreen();
    vector<string> a = {"SPEED 01", "SPEED 02", "SPEED 03", "SPEED 04", "SPEED 05", "TURN BACK"};
    int startRow = height/2 -1 - int(a.size())/2, startCol;
    int tmp;
    int m = a.size();
    do{
        for (int i=0; i<m; ++i){
            startCol = width/2 + 5 -1 - int(a[i].size())/2;
            if (i == cur){
                windowCanvas.draw(startCol, startRow+i, a[i], 23);
            }else{
                windowCanvas.draw(startCol, startRow+i, a[i], 15);
            }
        }
        windowCanvas.drawScreen();
        tmp = getch();
        if (tmp == 80){
            cur = (cur+1)%m;
        }else
        if (tmp == 72){
            cur = (cur-1+m)%m;
        }else
        if (tmp == 13){
            return cur + 1;
        }
    }while(true);
}

void Game::musicSetting() {
    windowCanvas.resetLim();
    int cur = 0;
    for (int i=0;i<width+10;++i)
    for (int j=0;j<height;++j){
        if (i==0 || j==0 || i==width+9 || j==height-1){
            windowCanvas.draw(i, j, '*', 10);
        }else
            windowCanvas.draw(i, j, ' ', 7);
    }

    windowCanvas.drawScreen();
    vector<string> a = {"TURN ON", "TURN OFF"};
    int startRow = height/2 -1 - int(a.size())/2, startCol;
    int tmp;
    int m = a.size();
    do{
        for (int i=0; i<m; ++i){
            startCol = width/2 + 5 -1 - int(a[i].size())/2;
            if (i == cur){
                windowCanvas.draw(startCol, startRow+i, a[i], 23);
            }else{
                windowCanvas.draw(startCol, startRow+i, a[i], 15);
            }
        }
        windowCanvas.drawScreen();
        tmp = getch();
        if (tmp == 80){
            cur = (cur+1)%m;
        }else
        if (tmp == 72){
            cur = (cur-1+m)%m;
        }else
        if (tmp == 13){
            if (turnOnMusic == false && cur == 0) {
                turnOnMusic = true;
                SoundControl* soundControl = SoundControl::GetInstance();
                soundControl->changeStatus();
            } else if (turnOnMusic == true && cur == 1) {
                turnOnMusic = false;
                SoundControl* soundControl = SoundControl::GetInstance();
                soundControl->changeStatus();
            }
            return;
        }
    }while(true);
}

void Game::updatePlayerData(){
    bool k =false;
    for(int i=0, ii=dataLst.size(); i<ii; ++i)
    if (dataLst[i].name == playerName){
        dataLst[i].level = level;
        dataLst[i].speed = speed;
        k = true;
        break;
    }
    if (!k)
        dataLst.emplace_back(playerName, level, speed);
    ofstream fo;
    fo.open("Data//data.txt");
    fo << dataLst.size() << endl;
    for (int i=0, ii=dataLst.size(); i<ii; ++i)
        fo << dataLst[i].name << ' ' << dataLst[i].level << ' ' << dataLst[i].speed << endl;
    fo.close();
}
