#include "point.hh"
#include "line.hh"
#include <cmath>
#include <string>
#include <sstream>
	
double Line::length(const Line& line) const{
	return pt1.distance(pt2);
}

std::string Line::toString() const {
	
	std::stringstream p;
	p << pt1.toString() << " -- " << pt2.toString() << "length = "	<< pt1.distance(pt2);
	return p.str();
}
