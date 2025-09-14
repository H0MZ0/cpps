#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

private:
	int					num;
	static const int	bits;

public:
	Fixed(); //Contructor
	Fixed(const int var1); //Int Contructor 
	Fixed(const float var2); //Float Contructor
	Fixed (const Fixed &other); //Copy constructor
	~Fixed(); //Destructor
	int		getRawBits( void ) const; //Getter
	void	setRawBits( int const raw ); //Setter
	float	toFloat( void ) const;
	int		toInt( void ) const;
	// Operators
	Fixed operator=(const Fixed &other); //assignment operator overloading
	friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);

};

#endif