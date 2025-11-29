#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called"<< std::endl;
	num = 0;
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
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
	if (this != &other) {num = other.num;}
	return *this;
}

Fixed::Fixed (const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	num = other.getRawBits();
}
