#pragma once

#include "entity.h"
#include "point.h"
enum Direction {
	UP,
	DOWN,
	RIGHT,
	LEFT
};

class Player : public Entity {
public:
	Player();
	~Player();
	std::string type_name();
	Point get_loca();
	void move(Point d);
	void die();
	void process_input(const char &ch, int lanes_width);
	void export_to_file(std::ofstream& fo);
	void import_from_file(std::ifstream& fi);
private:
};

