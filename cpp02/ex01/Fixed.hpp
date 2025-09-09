#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed{
private:
	int num;
	static const int bits;

public:
	Fixed(const int var1, const float var2); //Constructor
	Fixed (const Fixed &obj); //Copy constructor
	Fixed& operator=(const Fixed& other); //Copy assignment operator
	~Fixed(); //Destructor
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

};


#endif