#include "Fixed.hpp"

Fixed& Fixed::operator=(const Fixed &other){
	(void)other;
	return *this;
}

Fixed::Fixed() : num(0) {}

Fixed::Fixed(const int var1){
	num = var1 << bits;
}

Fixed::Fixed(const float var2){
	num = roundf(var2 * (1 << bits));
}

Fixed::Fixed (const Fixed &other){
	num = other.getRawBits();
}

int	Fixed::getRawBits(void) const{
	return num;
}

void	Fixed::setRawBits( int const raw ){
	num = raw;
}

Fixed::~Fixed(){
}

float	Fixed::toFloat( void ) const{
	return num / (float)(1 << bits);
}

int		Fixed::toInt( void ) const{
	return num >> bits;
}
