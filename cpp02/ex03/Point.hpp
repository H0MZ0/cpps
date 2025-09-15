#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <math.h>
#include "../ex02/Fixed.hpp"


class Point{

private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	Point(const float a, const float b);
	Point (const Point &other);

	Point& 		operator=(const Point &other);
	Fixed const	getX() const;
	Fixed const	getY() const;
	~Point();
};

bool			bsp( Point const a, Point const b, Point const c, Point const point);

#endif