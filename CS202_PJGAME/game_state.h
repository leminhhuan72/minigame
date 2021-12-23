#pragma once

#include "game_level.h"
#include <memory>
#include <string>

class Game_state : Window {
public:
	Game_state();
	void init();
	void update();
	void render();
	void update_and_render();
	void render_box();
	void import_from_file(const std::string& file_path);
	void export_to_file(const std::string& file_path);
	void process_input(const char &ch);
	void level_up();
	void play_again();
private:
	std::shared_ptr<Game_level> current_level = nullptr;
	bool is_dead = false;
};