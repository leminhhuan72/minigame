#include "windowControl.h"
void FixConsoleWindow() {
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//void clearScreen(int x, int y, int xx, int yy){
//    string s = "";
//    for (int i=x; i<=xx;++i)
//        s.push_back(' ');
//    for (int i=y;i<=yy;++i){
//        GotoXY(x,i);
//        cout << s;
//    }
//}

void drawPixel(Pixel u){
    GotoXY(u.x, u.y);
    cout << u.c;
}

void windowCanvas::draw(int x, int y, char c, int co){
    if (x>=xR || x<xL || y>=yR || y<yL) return;
    a[x][y] = c;
    color[x][y] = co;
}

void windowCanvas::draw(int x, int y, string s, int co){
    for (int i=0, ii=s.size(); i<ii; ++i){
        if (x+i>=xR || x+i<xL || y>=yR || y<yL) continue;
        a[x+i][y] = s[i];
        color[x+i][y] = co;
    }
}

