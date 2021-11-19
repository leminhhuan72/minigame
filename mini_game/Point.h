#ifndef  _POINT_H_
#define _POINT_H
#include <fstream>

struct Point {

	Point& operator+=(const Point& );
	Point operator+(const Point&);
	void export_to_file(std::ofstream& );
	void import_from_file(std::ifstream& );
	Point() = default;
	Point(int, int);
	int x, y; 
};
#endif // ! _POINT_H_
