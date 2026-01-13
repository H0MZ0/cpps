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

#endif