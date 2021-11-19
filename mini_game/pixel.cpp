#include "pixel.h"
#include "pixel.h"

Pixel::Pixel(Point p, char c, int color) :c(c), color(color), Point(p)
{
}

Pixel Pixel::operator+(const Point& other)
{
	Pixel tmp(*this);
	tmp += other;
	return tmp;
}