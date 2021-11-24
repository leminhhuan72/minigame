#pragma once

#include "Entity.h"
enum ObjectsType {
	OT_Car, OT_Bus, OT_Truck, OT_Bird, OT_Dinasour
};

class Objects : public Entity{





private : 
	void move();
	int tick_passed = 0;
	Point direction;

public :
	Objects();

	Objects(Point location, Point direction);
	Objects(Point loca, Point direction, int tick_passed);
	virtual ~Objects();
	virtual std::string type_name() = 0;
	virtual int obs_type() = 0;
	void do_tick();
	static std::shared_ptr<Objects> Create(ObjectsType type, Point loca_obs, Point dir);
	bool is_far_enough(Point p, int distance);
	void export_to_file(std::ofstream& fo);
	static std::shared_ptr<Objects> obs_import_from_file(std::ifstream& fi);
	virtual void die() = 0;
	

};