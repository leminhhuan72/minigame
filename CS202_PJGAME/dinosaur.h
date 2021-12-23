#pragma once
#include "obstacle.h"

class Dinosaur : public Obstacle {
public:
	Dinosaur();
	Dinosaur(Point loca, Point dir);
	Dinosaur(Point loca, Point direction, int tick_passed);
	~Dinosaur();
	std::string type_name();
	int obs_type();
	void die();
private:
};