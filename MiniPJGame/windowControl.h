#ifndef _windowControl_
#define _windowControl_

#include "pixel.h"
#include "windows.h"
#include <cstring>
#include <conio.h>
#include <string>
#include <iostream>

using namespace std;

void FixConsoleWindow();

void GotoXY(int x, int y);

void clearScreen();

void drawPixel(Pixel u);

#endif // _windowControl_
