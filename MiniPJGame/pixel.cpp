#include "pixel.h"

Pixel::Pixel(Point p, char c, char color) : Point(p), c(c), color(color)
{
}

Pixel Pixel::operator+(const Point& q)
{
	Pixel p(*this);
	p += q;
	return p;
}
