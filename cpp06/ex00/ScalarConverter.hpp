#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <iomanip>
# include <cmath>


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