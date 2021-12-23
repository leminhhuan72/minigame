#include "game_level.h"
#include <algorithm>
#include <iostream>
#include <string>

Game_level::Game_level(int level_id) : level_id(level_id)
{
	
}


Game_level::~Game_level()
{
	draw_entity(player, true);	// delete player when leveling up
}

void Game_level::init()
{
	init2();
	current_map->init();
}


void Game_level::init2() {
	Console::enable_console();
	int n_lanes = std::min(7, 4 + ((level_id - 1) / 2));
	int lane_width = 6;
	player = std::make_shared<Player>();
	set_pos({ 1, 1 }, { 44, 150 });
	current_map = std::make_shared<Game_map>(upper_left, lower_right, n_lanes, lane_width, level_id);
	level_display = std::make_shared<Window>(
		Point(upper_left.x, lower_right.y + 4),
		Point(upper_left.x + 7, lower_right.y + 21)
		);
	render_box();
}

void Game_level::update()
{
	current_map->update();
}

void Game_level::render()
{
	draw_entity(player);
	current_map->render();
}

void Game_level::update_and_render()
{
	draw_entity(player);
	current_map->update_and_render();
}

void Game_level::render_box()
{
	Console::make_background_sound(0);
	level_display->draw_rect('+');
	level_display->print_center_align("Level " + std::to_string(level_id), upper_left.x + 2);
	current_map->render_box();
	
}

bool Game_level::is_finished()
{
	return current_map->is_finished(player);
}

void Game_level::process_input(const char & ch)
{
	if (ch == KEY_DOWN || ch == KEY_UP || ch == KEY_LEFT || ch == KEY_RIGHT) {
		draw_entity(player, true);
		Point prev_loca = player->get_loca();
		player->process_input(ch, 6); //6: lane_width
		if (!contain(player))
			player->move(prev_loca);
	}
}

int Game_level::get_level_id()
{
	return level_id;
}

void Game_level::import_from_file(std::ifstream &fi)
{
	fi >> level_id;
	init2();
	level_display->import_from_file(fi);
	player->import_from_file(fi);
	current_map->import_from_file(fi);
}

void Game_level::export_to_file(std::ofstream& fo)
{
	fo << level_id << std::endl;
	level_display->export_to_file(fo);
	player->export_to_file(fo);
	current_map->export_to_file(fo);
}

bool Game_level::check_collide()
{
	if (current_map->check_collide(player)) {
		return true;
	}
	return false;
}
