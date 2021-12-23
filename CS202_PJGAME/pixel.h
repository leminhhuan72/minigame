#pragma once

#include "point.h"

struct Pixel : Point {
	//Pixel();
	Pixel(Point p, char c, int color);
	Pixel operator+(const Point& q);
	char c;
	int color;
};



