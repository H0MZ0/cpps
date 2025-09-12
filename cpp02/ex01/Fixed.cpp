#include "Fixed.hpp"
#include <cmath>

// const int Fixed::bits = 8;

Fixed::Fixed() : num(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int var1) {
    std::cout << "Int constructor called" << std::endl;
    num = var1 << bits; // Convert integer to fixed-point by multiplying by 2^bits
}

Fixed::Fixed(const float var2) {
    std::cout << "Float constructor called" << std::endl;
    num = static_cast<int>(roundf(var2 * (1 << bits))); // Convert float to fixed-point
}

Fixed::Fixed(const Fixed &obj) : num(obj.num) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->num = other.num;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return num;
}

void Fixed::setRawBits(int const raw) {
    num = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(num) / (1 << bits); // Convert fixed-point to float
}

int Fixed::toInt(void) const {
    return num >> bits; // Convert fixed-point to int by right-shifting
}

#include "Fixed.hpp"

std::ostream& operator<<(std::ostream &out, const Fixed &obj) {
    out << obj.toFloat();  // Insert the floating-point representation of the fixed-point number
    return out;
}
