#pragma once

#include "lane.h"
#include <memory>
#include <vector>
#include "player.h"

class Game_map : public Window {
public:
	Game_map(Point upper_left, Point lower_right, int n_lanes, int lane_width, int diff);
	virtual ~Game_map();
	bool is_finished(std::shared_ptr<Player> player);
	void init();
	void render_box();
	void update();
	void render();
	void update_and_render();	// optimized
	void import_from_file(std::ifstream& fi);
	void export_to_file(std::ofstream& fo);
	bool check_collide(std::shared_ptr<Player> player);
private:
	int difficulty;
	std::vector<std::shared_ptr<Lane>> lanes;
};

