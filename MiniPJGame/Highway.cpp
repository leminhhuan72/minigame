#include "Highway.h"

void Highway::draw(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    GotoXY(0, y);
    for (int i=0;i<140;++i)
        cout << "#";
    GotoXY(0, y+10);
    for (int i=0;i<140;++i)
        cout << "#";
    for (auto u: lst){
        u->draw();
    }
    GotoXY(141, y);
    if (status)
        SetConsoleTextAttribute(hConsole, 10);
    else
        SetConsoleTextAttribute(hConsole, 12);
    cout << int(timer);
}

void Highway::update(double t){
    t/=CLOCKS_PER_SEC;
    timer -= t;
    if (timer <= 0){
        status = !status;
        timer = 7;
        timepass = 0.4;
    }
    if (status){
        timepass -= t;
        if (timepass <= 0){
            timepass = 0.4;
            for (auto u: lst){
                u->moveTo(x, 0);
            }
        }
    }
}
