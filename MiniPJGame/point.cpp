#include "point.h"


Point& Point::operator+=(const Point& q)
{
	x += q.x;
	y += q.y;
	return *this;
}

Point Point::operator+(const Point& q)
{
	Point p(*this);
	p += q;
	return p;
}

void Point::export_to_file(std::ofstream & fo)
{
	fo << x << " " << y << std::endl;
}

void Point::import_from_file(std::ifstream & fi)
{
	fi >> x >> y;
}

Point::Point()
{
}

Point::Point(int x, int y) :x(x), y(y)
{
}
