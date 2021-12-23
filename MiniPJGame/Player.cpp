#include "Player.h"

void Player::draw(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    for (int i=0; i<h; ++i){
        GotoXY(x, y+i);
        cout << sprite[cur][i];
    }
}
