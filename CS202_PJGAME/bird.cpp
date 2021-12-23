#include "bird.h"
#include "console.h"
Bird::Bird()
{
	//location = { };
	load_icon();
}

Bird::Bird(Point loca, Point dir):Obstacle(loca, dir)
{
	load_icon(dir.y == -1);
}

Bird::Bird(Point loca, Point direction, int tick_passed) : Obstacle(loca, direction, tick_passed)
{
}

Bird::~Bird()
{
}

std::string Bird::type_name()
{
	return "Bird";
}

int Bird::obs_type()
{
	return 3;
}

void Bird::die()
{
	Console::make_sound("Data/Sound/bird_die.wav");
}
