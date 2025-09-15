#include "Point.hpp"

static Fixed sign(Point const &p1, Point const &p2, Point const &p3){
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
			- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	Fixed d1 = sign(point, a, b);
	Fixed d2 = sign(point, b, c);
	Fixed d3 = sign(point, c, a);
	if (d1 >= 1 && d2 >= 1 && d3 >= 1)
		return true;
	return false;
}
