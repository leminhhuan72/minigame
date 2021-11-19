#include "Point.h"



Point& Point::operator+=(const Point& q)
{
	/*
	this operator overload help to plus a GEOMETRIC vector to a point 
	*/
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

void Point::export_to_file(std::ofstream& fout)
{
	/*
	export this point to  a file 	
	*/
	fout << x << " " << y << std::endl;
}

void Point::import_from_file(std::ifstream& fin)
{
	fin >> x >> y;
}


Point::Point(int x, int y) :x(x), y(y) {};	
