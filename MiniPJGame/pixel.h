#pragma once

#include "point.h"

struct Pixel : Point {
	//Pixel();
	Pixel(Point p, char c, char color);
	Pixel operator+(const Point& q);
	char c, color;
};



