#pragma once
#include "window.h"
#include <vector>
#include <conio.h>

enum MENU_NAME{
	NEW_GAME,
	LOAD_GAME,
	SETTINGS,
	QUIT
};

enum PAUSE_MENU_NAME {
	RESUME2,
	NEW_GAME2,
	SAVE_GAME2,
	LOAD_GAME2,
	SETTINGS2,
	QUIT2
};

class Menu : public Window {
public:
	Menu(bool is_main_menu = true);
	virtual ~Menu();

	void load_menu();
	int get_input();
private:
	std::string logo_filepath;
	std::vector<std::string> content;
	Point start_point;
	int max_length; // max length of content menu
	int cursor;
	std::vector<Window> rect; // contain rect of content i
	int logo_size = 0;
	void load_logo();
	void Unchoose(int id);
	void Choose(int id);
};

