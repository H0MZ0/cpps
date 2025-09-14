#include "Fixed.hpp"

// Comparison
bool Fixed::operator==(const Fixed& other) const{
	return this->num == other.num;
}

bool Fixed::operator<(const Fixed& other) const{
	return this->num < other.num;
}

bool Fixed::operator!=(const Fixed& other) const{
	return this->num != other.num;
}

bool Fixed::operator>(const Fixed& other) const{
	return this->num > other.num;
}

bool Fixed::operator<=(const Fixed& other) const{
	return this->num <= other.num;
}

bool Fixed::operator>=(const Fixed& other) const{
	return this->num >= other.num;
}

// Arithmetic

Fixed Fixed::operator+(const Fixed& other) const{
	int sum = this->num + other.num;
	Fixed Fx;
	Fx.setRawBits(sum);
	return Fx;
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

Fixed Fixed::operator/(const Fixed& other) const{
	Fixed	result;
	result.num = (this->num << bits) / other.num;
	return result;
} 

// increment/decrement
Fixed&	Fixed::operator++(){
	num++;
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed&	Fixed::operator--(){
	num--;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed temp(*this);
	--(*this);
	return temp;
}

// Others

const Fixed&	min(const Fixed& a, const Fixed& b){
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

const Fixed& max(const Fixed& a, const Fixed& b){
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}



Fixed& 		min(Fixed& a, Fixed& b){
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}
Fixed&		max(Fixed& a, Fixed& b){
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
