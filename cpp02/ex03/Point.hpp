#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"


class Point{

private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	Point(const float a, const float b);
	Point (const Point &other);

	Point& 		operator=(const Point &other);
	Fixed		getX() const;
	Fixed		getY() const;
	~Point();

};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif