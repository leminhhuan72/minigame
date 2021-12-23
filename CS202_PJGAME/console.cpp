#include "console.h"
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

namespace Console {
	void gotoXY(int x, int y) {
		COORD pos = { y, x };
		SetConsoleCursorPosition(HOUT, pos);
	}
	void clear_screen()
	{
		system("cls");
	}
	void full_screen()
	{
		HWND hWnd = GetConsoleWindow();
		ShowWindow(hWnd, SW_SHOWMAXIMIZED);
		//system("mode 1000");
		//SetConsoleDisplayMode(HOUT, CONSOLE_FULLSCREEN_MODE, NULL);
	}
	void SetColor(int ForgC)
	{
		ForgC = 15 - ForgC;
		WORD wColor;

		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		//We use csbi for the wAttributes word.
		if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
		{
			//Mask out all but the background attribute, and add in the forgournd color
			wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
			SetConsoleTextAttribute(hStdOut, wColor);
		}
		return;
	}

	int sound_active = true;

	void make_background_sound(bool is_menu)
	{
		if (!sound_active) return;
		std::string st = "Data/Sound/Background2.wav";
		if (is_menu) st = "Data/Sound/Background.wav";
		//PlaySoundA((LPCSTR)(st.c_str()), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
	}

	void make_sound(const char* filename)
	{
		if (!sound_active) return;
		//PlaySoundA((LPCSTR)(filename), NULL, SND_FILENAME | SND_ASYNC);
	}

	void reverse_sound()
	{
		sound_active ^= 1;
		if (sound_active) {
			make_background_sound();
		} else{
		    //PlaySoundA(NULL, NULL, NULL);
		}
	}
	bool status_console = true;
	bool status()
	{
		return status_console;
	}
	void enable_console()
	{
		status_console = true;
	}

	void disabled_console()
	{
		status_console = false;
	}


	/*
	Name         | Value
	             |
	Black        |   15
	Blue         |   14
	Green        |   13
	Cyan         |   12
	Red          |   11
	Magenta      |   10
	Brown        |   9
	Light Gray   |   8
	Dark Gray    |   7
	Light Blue   |   6
	Light Green  |   5
	Light Cyan   |   4
	Light Red    |   3
	Light Magenta|   2
	Yellow       |   1
	White        |   0
	*/
}
