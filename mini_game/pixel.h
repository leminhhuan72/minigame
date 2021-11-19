#ifndef _PIXEL_H_
#define _PIXEL_H_
#include "Point.h"
struct Pixel : public Point {
	//Pixel();
	Pixel(Point , char c, int color);
	Pixel operator+(const Point& );
	char c;
	int color;
};

#endif // !_PIXEL_H_
