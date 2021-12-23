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

void clearScreen(){
    string tmp = "";
    for (int i=0; i<=140; ++i)
        tmp.push_back(' ');
    for (int i=0;i<=40;++i){
        GotoXY(0, i);
        cout << tmp;
    }
}

void drawPixel(Pixel u){
    GotoXY(u.x, u.y);
    cout << u.c;
}

/**<
1	Blue	9	Light Blue
2	Green	0	Black
3	Aqua	A	Light Green
4	Red	    B	Light Aqua
5	Purple	C	Light Red
6	Yellow	D	Light Purple
7	White	E	Light Yellow
8	Gray	F	Bright White
 */

