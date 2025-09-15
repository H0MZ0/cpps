#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

private:
	int					num;
	static const int	bits;

public:
	Fixed(); //Contrustor
	Fixed(const int var1); //Int Contrustor 
	Fixed(const float var2); //Float Contrustor
	Fixed (const Fixed &other); //Copy constructor
	~Fixed(); //Destructor
	int		getRawBits( void ) const; //Getter
	void	setRawBits( int const raw ); //Setter
	float	toFloat( void ) const;
	int		toInt( void ) const;
	// Operators
	Fixed operator=(const Fixed &other); //assignment operator overloading
	friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
	// Comparison operators
	bool operator==(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	bool operator>(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	// bool operator>=(const Fixed& other) const;

	// Arithmetic operators
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Increment/Decrement
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	// Others
	static Fixed& 		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

};

#endif