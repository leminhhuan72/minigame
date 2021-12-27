#ifndef _windowControl_
#define _windowControl_

#include "pixel.h"
#include "windows.h"
#include <cstring>
#include <conio.h>
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

void FixConsoleWindow();

void GotoXY(int x, int y);

//void clearScreen(int x, int y, int xx, int yy);

void drawPixel(Pixel u);

class windowCanvas{
private:
    int n, m;
    int xL, xR, yL, yR;
    vector<vector<char> > a, b; // a new, b old
    vector<vector<int> > cOld,color;
public:
    windowCanvas():n(155), m(45),
            a(vector<vector<char> > (n, vector<char> (m, ' '))),
            b(vector<vector<char> > (n, vector<char> (m, ' '))),
            cOld(vector<vector<int> > (n, vector<int> (m, 7))),
            color(vector<vector<int> > (n, vector<int> (m, 7))){
        xL = 0;
        xR = n;
        yL = 0;
        yR = m;

    }
    void draw(int x, int y, char c, int co);
    void draw(int x, int y, string s, int co);
    void drawScreen();
    void clearScreen();
    void resetLim();
    void setLim(int x1, int y1, int x2, int y2);
};

#endif // _windowControl_
