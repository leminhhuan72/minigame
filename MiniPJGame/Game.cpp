#include "Game.h"

void Game::startGame(){
    do{
        switch (showMenu()){
        case 0:
            start();
            break;
        case 1:
            loadGame();
            break;
        case 2:
            setting();
            break;
        default:
            break;
        }
    }while(true);
}

int Game::showMenu(){
    int cur = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    for (int i=1;i<=width;++i)
    for (int j=1;j<=height;++j){
        if (i==1 || j==1 || i==width || j==height){
            drawPixel(Pixel(Point(i,j), '*', 'F'));
        }
    }
    vector<string> a = {"NEW  GAME", "LOAD GAME", "SETTING", "QUIT"};
    int startRow = height/2 - int(a.size())/2, startCol;
    SetConsoleTextAttribute(hConsole, 15);
    int tmp;
    int m = a.size();
    do{
        for (int i=0; i<m; ++i){
            startCol = width/2 - int(a[i].size())/2;
            if (i == cur){
                SetConsoleTextAttribute(hConsole, 23);
                GotoXY(startCol, startRow+i);
                cout << a[i];
                SetConsoleTextAttribute(hConsole, 15);
            }else{
                GotoXY(startCol, startRow+i);
                cout << a[i];
            }
        }

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

void Game::start(){
    Object* p = new Player(20, 20);
    Highway h(-1, 5);
    int tmp;
    timepass = 0;
    double timing = 0;

    auto updateGame = [&](){
        while(true){
            double t_tmp = clock() - timing;
            timing = clock();
            timepass += t_tmp;
            h.update(t_tmp);
            if (timepass < delta) continue;
            timepass -= delta;
            clearScreen();
            p->draw();
            h.draw();
        }
    };

    thread t1(updateGame);
    while(true){
        Sleep(500);
        tmp = getch();
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
        p->draw();
    }
}

void Game::loadGame(){

}

void Game::setting(){

}
