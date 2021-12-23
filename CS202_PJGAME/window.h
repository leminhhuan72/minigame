#pragma once
#include <iostream>
#include "point.h"
#include "console.h"
#include "entity.h"

class Window {
public:
	Window();
	Window(Point upper, Point lower);
	virtual ~Window();

	void turn_on_reverse_color();
	void turn_off_reverse_color();

	bool contain(Point x);
	bool contain(std::shared_ptr<Entity> x);
	void draw_full_rect(char c = '*');
	void draw_rect(char c = '*');
	void draw_road_marking(bool first, bool last);
	void draw_entity(std::shared_ptr<Entity> entity, bool isErase = false);

	void print_center_align(std::string st, int line);
	
	void set_pos(Point upper, Point lower);

	void import_from_file(std::ifstream& fi);
	void export_to_file(std::ofstream& fo);

protected:
	Point upper_left, lower_right;

};
