#include "bus.h"
#include "console.h"

Bus::Bus()
{
	//location = { };
	load_icon();
}

Bus::Bus(Point loca, Point dir):Obstacle(loca, dir)
{
	load_icon(dir.y == -1);
}

Bus::Bus(Point loca, Point direction, int tick_passed) : Obstacle(loca, direction, tick_passed)
{
}

Bus::~Bus()
{
}

std::string Bus::type_name()
{
	return "Bus";
}

int Bus::obs_type()
{
	return 1;
}

void Bus::die()
{
	Console::make_sound("Data/Sound/car_die.wav");
}
