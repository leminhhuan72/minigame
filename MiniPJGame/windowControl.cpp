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

void windowCanvas::drawScreen(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int x=0; x<n; ++x)
    for (int y=0; y<m; ++y)
    if (a[x][y] != b[x][y] || color[x][y] != cOld[x][y]){
        b[x][y] = a[x][y];
        cOld[x][y] = color[x][y];
        GotoXY(x, y);
        SetConsoleTextAttribute(hConsole, color[x][y]);
        cout << a[x][y];
    }
}

void windowCanvas::resetLim(){
    xL = 0;
    xR = n;
    yL = 0;
    yR = m;
}

void windowCanvas::setLim(int x1, int y1, int x2, int y2){
    xL = x1;
    xR = x2;
    yL = y1;
    yR = y2;
}

void windowCanvas::clearScreen(){
    for (int x=0; x<n; ++x)
    for (int y=0; y<m; ++y){
        a[x][y] = ' ';
        color[x][y] = 9;
    }
}
