#ifndef LINE_HH_
#define LINE_HH_
#include <string>
#include "point.hh"
class Line{
	public:
	const Point pt1, pt2;

	//constructor
	Line(Point pt1 = Point(0,0), Point pt2 = Point(0,0)) : pt1(pt1), pt2(pt2) { }
	//length method
	double length(const Line& line) const;
	//toString method
	std::string toString() const;
};

#endif 
