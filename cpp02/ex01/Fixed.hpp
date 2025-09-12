#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
private:
    int num;
    static const int bits = 8;

public:
    Fixed();
    Fixed(const int var1);
    Fixed(const float var2);
    Fixed(const Fixed &obj);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    friend std::ostream& operator<<(std::ostream &out, const Fixed &obj);
};

#endif
