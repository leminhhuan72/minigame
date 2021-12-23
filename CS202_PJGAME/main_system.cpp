#include "main_system.h"
#include "Windows.h"
#include <conio.h>
#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include "console.h"
#include "random.h"

void Game_module::show_main()
{
	Random::Init();
	Console::full_screen();

	Menu menu;
	while (true) {
		Console::clear_screen();
		menu.set_pos({ 1, 1 }, { 40, 150 });
		menu.load_menu();
		switch (menu.get_input()) {
		case MENU_NAME::NEW_GAME:
			start_new_game();
			break;
		case MENU_NAME::LOAD_GAME:
			// Load game
			load_game();
			break;
		case MENU_NAME::SETTINGS:
			// Settings game
			Console::reverse_sound();
			break;
		case MENU_NAME::QUIT:
			exit(0);
		}
	}
	//start_game();
}

int Game_module::show_pause_menu()
{
	Menu menu(0);
	Console::clear_screen();
	menu.set_pos({ 1, 1 }, { 40, 150 });
	menu.load_menu();
	int choose = menu.get_input();
	switch (choose) {
	case PAUSE_MENU_NAME::RESUME2:
		break;
	case PAUSE_MENU_NAME::NEW_GAME2:
		current_state = std::make_shared<Game_state>();
		current_state->init();
		break;
	case PAUSE_MENU_NAME::LOAD_GAME2:
		// Load game
		load_game();
		break;
	case PAUSE_MENU_NAME::SAVE_GAME2:
		// Save game
		save_game();
		break;
	case PAUSE_MENU_NAME::SETTINGS2:
		// Settings game
		//show_setting_menu();
		Console::reverse_sound();
		break;
	case PAUSE_MENU_NAME::QUIT2:
		current_state = nullptr;
		return -1;
	}
	return 0;
}

void Game_module::show_setting_menu()
{

}

void Game_module::do_menu_choice()
{
}

void Game_module::start_new_game()
{
	auto new_state = std::make_shared<Game_state>();
	new_state->init();
	start_game(new_state);
}

void Game_module::start_game(std::shared_ptr<Game_state> start_state)
{
	current_state = start_state;
	current_state->render_box();
	std::mutex mtx;
	bool is_running = true, is_pause = false;
	current_state->render();

	bool need_render_again = false;

	auto main_game_loop = [&](char &ch) //char input
	{
		while (true) {
			{
				std::lock_guard<std::mutex> locker(mtx);
				if (!is_running) return;
				if (is_pause) continue;
			}
			if (need_render_again) {
				current_state->render_box();
				current_state->update();
				current_state->render();
				need_render_again = false;
			}
			current_state->update_and_render();
			current_state->process_input(ch);
			ch = '.';
			//std::cout << "Main game loop\n";
			// Sleep(30);
		}
	};

	char ch = '.';

	std::thread t1(main_game_loop, std::ref(ch));
	// input loop
	auto return_to_menu = [&]() {
		mtx.lock();
		is_running = false;
		mtx.unlock();
		t1.join();
	};
	while (true) {

		// process input
		ch = _getch();
		//std::cout << "Input: " << ch << '\n';
		switch (ch) {
		case 'a':
			return_to_menu();
			return;
		case 'p':
			// Pause menu
		case ESC:
			// Pause menu
			if (!Console::status()) {
				break;
			}
			is_pause ^= 1;
			if (is_pause) {
				Sleep(500);
				int signal = show_pause_menu();
				if (signal == -1) {
					// return to menu
					return_to_menu();
					return;
				}
				need_render_again = true;
				is_pause ^= 1;
			}
			break;
		}
	}
}

void Game_module::load_game()
{
	system("md SaveGame");
	// Get file name
	std::string filename = "First";
	filename = "SaveGame/" + filename + ".map";
	auto new_state = std::make_shared<Game_state>();
	new_state ->import_from_file(filename);
	if (current_state == nullptr) start_game(new_state);
	else current_state = new_state;
}

void Game_module::save_game()
{
	// Get file name
	system("md SaveGame");
	std::string filename = "First";
	filename = "SaveGame/" + filename + ".map";
	current_state->export_to_file(filename);
}
