#pragma once
#include "obstacle.h"

class Car : public Obstacle {
public:
	Car();
	Car(Point loca, Point dir);
	Car(Point loca, Point direction, int tick_passed);
	~Car();
	std::string type_name();
	int obs_type();
	void die();
private:
};