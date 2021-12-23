#include "dinosaur.h"
#include "console.h"

Dinosaur::Dinosaur()
{
	//location = { };
	load_icon();
}

Dinosaur::Dinosaur(Point loca, Point dir):Obstacle(loca, dir)
{
	load_icon(dir.y == -1);
}

Dinosaur::Dinosaur(Point loca, Point direction, int tick_passed) : Obstacle(loca, direction, tick_passed)
{
}

Dinosaur::~Dinosaur()
{

}

std::string Dinosaur::type_name()
{
	return "Dinosaur";
}

int Dinosaur::obs_type()
{
	return 4;
}

void Dinosaur::die()
{
	Console::make_sound("Data/Sound/dinosaur_die.wav");

}
