#include "Game.h"

void Game::startGame(){
    bool isRunning = true;
    do{
        switch (showMenu()){
        case 0:
            playerName = getPlayerName();
            start();
            break;
        case 1:
            loadGame();
            break;
        case 2:
            setting();
            break;
        default:
            isRunning = false;
            break;
        }
    }while(isRunning);
}

int Game::showMenu(){
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
    int dis = 3-u%3;
    for (int i=0;i<lane; ++i)
        a.emplace_back((i&1?1:-1), 8+i*7, dis);
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
    int tmp;
    do{
        tmp = getch();
    }while(tmp != 27 &&tmp!=121);   //check choice : esc or yes to replay this level
    if(tmp==121)return true;
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
    windowCanvas.draw(30, startRow, "Enter your name (Enter to finish)\n", 10);
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
        windowCanvas.draw(30, startRow, "Enter your name (Enter to finish)\n", 10);
        tmp = getch();
        if (tmp == 13)
            break;
        else
        if (tmp == 8){
            if (!name.empty())
                name.pop_back();
        }else
            name.push_back(char(tmp));
        windowCanvas.draw(30, startRow+1, name, 13);
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
    auto updateGame = [&](){
        while(isRunning){
            /// update level
            if (p->isImpactY(4)){
                ++level;
                wayLst.clear();
                wayLst = buildLevel(level);
                delete p;
                p = new Player(70, 39);
            }
            /// check impact
            if (checkImpact(wayLst, p)){
                isRunning = false;
                break;
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
    if(showEnding())start();
}

void Game::loadGame(){

}

void Game::setting(){

}
