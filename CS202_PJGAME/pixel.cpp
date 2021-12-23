#include "pixel.h"

Pixel::Pixel(Point p, char c, int color) :c(c), color(color), Point(p)
{
}

Pixel Pixel::operator+(const Point& q)
{
	Pixel p(*this);
	p += q;
	return p;
}