#pragma once
#include "entity.h"
#include <memory>

enum ObstacleType {
	OT_Car, OT_Bus, OT_Truck, OT_Bird, OT_Dinasour
};

class Obstacle : public Entity {
public:
	Obstacle();

	Obstacle(Point loca, Point direction);
	Obstacle(Point loca, Point direction, int tick_passed);
	virtual ~Obstacle();
	virtual std::string type_name() = 0;
	virtual int obs_type() = 0;
	void do_tick(); 
	static std::shared_ptr<Obstacle> Create(ObstacleType type, Point loca_obs, Point dir);
	bool is_far_enough(Point p, int distance);
	void export_to_file(std::ofstream& fo);
	static std::shared_ptr<Obstacle> obs_import_from_file(std::ifstream &fi);
	virtual void die() = 0;
private:
	void move();
	int tick_passed = 0;
	Point direction;
};

