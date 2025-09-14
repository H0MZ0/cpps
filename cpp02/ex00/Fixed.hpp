#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed{
private:
	int 				num;
	static const int	bits;

public:
	Fixed(); //Constructor
	Fixed (const Fixed &obj); //Copy constructor
	Fixed& operator=(const Fixed& other); //Copy assignment operator
	~Fixed(); //Destructor
	int getRawBits( void ) const; // Getter
	void setRawBits( int const raw ); // Setter

};


#endif