#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>


class ScalarConverter{
    private:
    ScalarConverter();

    public:
    static void print_types(std::string const & v, int type);
    static void convert(std::string const & value);

};

#endif