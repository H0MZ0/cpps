#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

private:
	int					num;
	static const int	bits = 8;

public:
	Fixed(); //Contrustor
	Fixed (const Fixed &other); //Copy constructor
	Fixed& operator=(const Fixed &other); //assignment operator overloading
	~Fixed(); //Destructor
	int		getRawBits( void ) const; //Getter
	void	setRawBits( int const raw ); //Setter

};

#endif