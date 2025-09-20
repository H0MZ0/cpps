#include "Fixed.hpp"

Fixed::Fixed() : num(0){
	std::cout << "Default constructor called"<< std::endl;
}

Fixed::Fixed(const int var1){
	std::cout << "Int constructor called" << std::endl;
	num = var1 << bits;
}

Fixed::Fixed(const float var2){
	std::cout << "Float constructor called" << std::endl;
	num = roundf(var2 * (1 << bits));
}

Fixed::Fixed (const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	num = other.getRawBits();
}

int	Fixed::getRawBits(void) const{
	return num;
}

void	Fixed::setRawBits( int const raw ){
	num = raw;
}

Fixed::~Fixed(){
	std::cout << "Destructor called"<< std::endl;
}

Fixed& Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other){
		return *this;
	}
	num = other.num;
	return *this;
}

float	Fixed::toFloat( void ) const{
	return num / (float)(1 << bits);
}

int		Fixed::toInt( void ) const{
	return num >> bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj){
	os << obj.toFloat();
	return os;
}