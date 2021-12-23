#pragma once
#include "obstacle.h"

class Truck : public Obstacle {
public:
	Truck();
	Truck(Point loca, Point dir);
	Truck(Point loca, Point direction, int tick_passed);
	~Truck();
	std::string type_name();
	int obs_type();
	void die();
private:
};