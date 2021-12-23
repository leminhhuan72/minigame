#include "car.h"
#include "console.h"

Car::Car()
{
	//location = { };
	load_icon();
}

Car::Car(Point loca, Point dir):Obstacle(loca, dir)
{
	load_icon(dir.y == -1);
}

Car::Car(Point loca, Point direction, int tick_passed) : Obstacle(loca, direction, tick_passed)
{
}

int Car::obs_type()
{
	return 0;
}

void Car::die()
{
	Console::make_sound("Data/Sound/car_die.wav");
}

Car::~Car()
{
}

std::string Car::type_name()
{
	return "Car";
}
