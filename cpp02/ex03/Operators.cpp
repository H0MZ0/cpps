#include "Fixed.hpp"

bool Fixed::operator>=(const Fixed& other) const{
	return this->num >= other.num;
}

bool Fixed::operator>(const Fixed& other) const{
	return this->num > other.num;
}

Fixed Fixed::operator-(const Fixed& other) const{
	int sum = this->num - other.num;
	Fixed Fx;
	Fx.setRawBits(sum);
	return Fx;
}

Fixed Fixed::operator*(const Fixed& other) const{
	Fixed	result;
	result.num = (this->num * other.num) >> bits;
	return result;
}
