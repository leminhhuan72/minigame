#pragma once

#include <iostream>

#define HOUT GetStdHandle(STD_OUTPUT_HANDLE)
#define HIN GetStdHandle(STD_INPUT_HANDLE)
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13 
#define ESC 27

enum COLOR {
	WHITE,
	YELLOW,
	LIGHT_MAGENTA,
	LIGHT_RED,
	LIGHT_CYAN,
	LIGHT_GREEN,
	LIGHT_BLUE,
	DARK_GRAY,
	LIGHT_GRAY,
	BROWN,
	MAGENTA,
	RED,
	CYAN,
	GREEN,
	BLUE,
	BLACK
};

namespace Console
{
	void gotoXY(int x, int y);
	void clear_screen();
	void full_screen();
	void SetColor(int ForgC);
	void make_background_sound(bool is_menu = true);
	void make_sound(const char* filename);
	void reverse_sound();
	bool status();
	void enable_console();
	void disabled_console();
}
