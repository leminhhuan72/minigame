#pragma once

#include "window.h"
#include "obstacle.h"
#include "player.h"
#include <vector>
#include <memory>
#include <thread>

enum LaneType {
	LT_Lane, LT_Railway
};

class Lane : public Window {
public:
	Lane(std::shared_ptr<Lane> lane);
	Lane(Point upper, Point lower, bool is_special = false);
	virtual ~Lane();

	static std::shared_ptr<Lane> Create(LaneType type, std::shared_ptr<Lane> old_lane);
	void init();
	virtual void render();
	virtual void update();
	virtual void update_and_render();	// optimized
	void export_to_file(std::ofstream& fo);
	void import_from_file(std::ifstream& fi);
	virtual bool check_collide(std::shared_ptr<Player> player);
	void load_finish_lane(bool isErase = false);
	void set_cooldown(int x);
	virtual int type();
protected:
	std::vector<std::shared_ptr<Obstacle>> obstacles;
	int tick_passed = 0;
	bool is_rendered = false;
	int cooldown = 0;		// time between consecutive obstacle generation
	bool is_stop = true;
	bool is_special; // true when is first and last lane
	void update_traffic_lights();
	void render_traffic_light();
	void unrender_traffic_light();
private:
	int traffic_time = 0; // change between stop and non-stop
	bool dir_to_right;	
	void generate_obstacles();
};

