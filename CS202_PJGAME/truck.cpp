#include "truck.h"
#include "console.h"

Truck::Truck()
{
	//location = { };
	load_icon();
}

Truck::Truck(Point loca, Point dir):Obstacle(loca, dir)
{
	load_icon(dir.y == -1);
}

Truck::Truck(Point loca, Point direction, int tick_passed) : Obstacle(loca, direction, tick_passed)
{
}

Truck::~Truck()
{
}

std::string Truck::type_name()
{
	return "Truck";
}

int Truck::obs_type()
{
	return 2;
}

void Truck::die()
{
	Console::make_sound("Data/Sound/car_die.wav");

}
