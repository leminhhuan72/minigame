#include <iostream>
#include <Windows.h>
#include "cGame.h"
#include <thread>
#include <stdlib.h>
#include "multiThread.h"
#include <conio.h>
using namespace std;


void FixConsoleWindow() {
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
void main()
{
	cg = new CGAME();
	int temp;
	FixConsoleWindow();
	cg.startGame();
	thread t1(SubThread);
	while (1)
	{
		temp = toupper(getch());
		if (!cg.getPeople().isDead())
		{
			if (temp == 27) {
				cg.exitGame(t1.native_handle());
				return;

			}
			else if (temp == 'P') {
				cg.pauseGame(t1.native_handle());

			}
			else {
				cg.resumeGame((HANDLE)t1.native_handle());
				MOVING = temp; //Cập nhật bước di chuyển

			}
		}
		else
		{
			if (temp == 'Y') cg.startGame();
			else {
				cg.exitGame(t1.native_handle());
				return;

			}
		}
	}
}