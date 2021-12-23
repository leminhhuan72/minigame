#include "pixel.h"

Pixel::Pixel(Point p, char c, char color) :c(c), color(color), Point(p)
{
}

Pixel Pixel::operator+(const Point& q)
{
	Pixel p(*this);
	p += q;
	return p;
}
