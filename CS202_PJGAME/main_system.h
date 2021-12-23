#pragma once

#include "game_state.h"
#include "menu.h"

#include <memory>

class Game_module {
public:
	void show_main();
	int show_pause_menu();
	void show_setting_menu();
private:
	void do_menu_choice();
	void start_new_game();
	void start_game(std::shared_ptr<Game_state> start_state);
	void load_game();
	void save_game();
	std::shared_ptr<Game_state> current_state;
};