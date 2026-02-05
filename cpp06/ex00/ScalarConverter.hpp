#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <cctype>
# include <limits>
# include <cmath>
# include <iomanip>
# include <cerrno>
# include <sstream>

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const & src);
        ScalarConverter & operator=(ScalarConverter const & src);
        ~ScalarConverter();

    public:
        static void convert(std::string const & value);
        
}; 

void printDouble(double value);
void printFloat(double value);
void printInt(double value);
void printChar(double value);
double parseToDouble(const std::string &s, bool &error);
bool isFloat(const std::string &s);
bool isDouble(const std::string &s);
bool isInt(const std::string &s);
bool isChar(const std::string &s);

#endif