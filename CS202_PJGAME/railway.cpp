#include "railway.h"
#include <Windows.h>

using Console::gotoXY;

Railway::Railway(std::shared_ptr<Lane> lane): Lane(lane)
{
}

Railway::Railway(Point upper, Point lower, bool is_special) : Lane(upper, lower, is_special)
{
	
}

Railway::~Railway()
{
	if (is_rendered) {
		unrender_traffic_light();
		for (int i = upper_left.x + 1; i <= lower_right.x - 1; ++i) {
			gotoXY(i, upper_left.y);
			for (int j = upper_left.y; j <= lower_right.y; ++j)
				putchar(' ');
		}
	}
}

void Railway::render()
{
	if (!is_special && !is_rendered) {
		render_traffic_light();
		for (int i = upper_left.x + 1; i <= lower_right.x - 1; ++i) {
			gotoXY(i, upper_left.y);
			for (int j = upper_left.y; j <= lower_right.y; ++j)
				putchar(!is_stop ? '-' : ' ');
		}

		is_rendered = true;
	}
}

void Railway::update()
{
	if (is_special) return;
	
	
	if (is_rendered)
		unrender_traffic_light();

	update_traffic_lights();
	render_traffic_light();

	is_rendered = false;
	
}

void Railway::update_and_render()
{
	if (is_special) return;
	bool prev_stop = is_stop;
	update();
	if (prev_stop != is_stop)
		render();
	else is_rendered = true;
}

bool Railway::check_collide(std::shared_ptr<Player> player)
{
	if (!is_stop && contain(player)) {
		Console::disabled_console();
		Console::make_sound("Data/Sound/Railway.wav");
		Sleep(2000);
		player->die();
		return true;
	}
	return false;
}

int Railway::type()
{
	return LT_Railway;
}
