#include "CBird.h"
#include "ConsoleHelp.h"
bird::bird()
{
	//location = { };
	load_icon();
}

bird::bird(Point loca, Point dir) :Objects(loca, dir)
{
	load_icon(dir.y == -1);
}

bird::bird(Point loca, Point direction, int tick_passed) : Obstacle(loca, direction, tick_passed)
{
}

bird::~bird()
{
}

string bird::type_name()
{
	return "bird";
}

int bird::obs_type()
{
	return 3;
}

void bird::die()
{
	Console::make_sound("Data/Sound/bird_die.wav");
}
