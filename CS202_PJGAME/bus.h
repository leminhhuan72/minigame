#pragma once
#include "obstacle.h"

class Bus : public Obstacle {
public:
	Bus();
	Bus(Point loca, Point dir);
	Bus(Point loca, Point direction, int tick_passed);
	~Bus();
	std::string type_name();
	int obs_type();
	void die();
private:
};