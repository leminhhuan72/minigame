#pragma once
#include "obstacle.h"

class Bird : public Obstacle {
public:
	Bird();
	Bird(Point loca, Point dir);
	Bird(Point loca, Point direction, int tick_passed);
	~Bird();
	std::string type_name();
	int obs_type();
	void die();
private:
};
