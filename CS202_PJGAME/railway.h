#pragma once
#include "lane.h"

class Railway : public Lane {
public:
	Railway(std::shared_ptr<Lane> lane);
	Railway(Point upper, Point lower, bool is_special = false);
	~Railway();
	void render();
	void update();
	void update_and_render();
	bool check_collide(std::shared_ptr<Player> player);
	int type();
};