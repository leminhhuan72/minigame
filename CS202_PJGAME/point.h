#pragma once
#include <fstream>

struct Point {
	int x, y;
	Point();
	Point(int x, int y);
	Point& operator+=(const Point& q);
	Point operator+(const Point& q);
	void export_to_file(std::ofstream& fo);
	void import_from_file(std::ifstream& fi);
};

