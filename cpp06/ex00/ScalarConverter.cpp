#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const & src) {(void)src;}
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src) {(void)src; return *this;}
ScalarConverter::~ScalarConverter() {}







bool isChar(const std::string &s)
{
    return (s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]));
}

bool isInt(const std::string &s)
{
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i >= s.length())
        return false;
    for (; i < s.length(); i++)
        if (!std::isdigit(s[i]))
            return false;
    return true;
}

bool isDouble(const std::string &s)
{
    size_t i = 0;
    bool hasDot = false;

    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i >= s.length())
        return false;

    for (; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (!std::isdigit(s[i]))
            return false;
    }
    return hasDot;
}

bool isFloat(const std::string &s)
{
    if (s.length() < 2 || s[s.length() - 1] != 'f')
        return false;
    std::string noF = s.substr(0, s.length() - 1);
    return isDouble(noF) || isInt(noF);
}

// Conversion to double (main parsing function)
double parseToDouble(const std::string &s, bool &error)
{
    error = false;
    
    if (s == "nan" || s == "nanf")
        return std::numeric_limits<double>::quiet_NaN();
    if (s == "+inf" || s == "+inff")
        return std::numeric_limits<double>::infinity();
    if (s == "-inf" || s == "-inff")
        return -std::numeric_limits<double>::infinity();
    
    if (isChar(s))
        return static_cast<double>(s[0]);
    
    std::string toParse = s;
    if (isFloat(s))
        toParse = s.substr(0, s.length() - 1);
    
    char *endptr;
    errno = 0;
    double result = std::strtod(toParse.c_str(), &endptr);
    
    if (*endptr != '\0' || errno == ERANGE)
        error = true;
    
    return result;
}

// Print char conversion
void printChar(double value)
{
    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    
    if (value < std::numeric_limits<char>::min() || 
        value > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    
    char c = static_cast<char>(value);
    if (!std::isprint(static_cast<unsigned char>(c)))
    {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    
    std::cout << "char: '" << c << "'" << std::endl;
}

// Print int conversion
void printInt(double value)
{
    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    
    if (value < std::numeric_limits<int>::min() || 
        value > std::numeric_limits<int>::max())
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    
    std::cout << "int: " << static_cast<int>(value) << std::endl;
}  

// Print float conversion
void printFloat(double value)
{
    float f = static_cast<float>(value);
    
    if (std::isnan(f))
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    
    if (std::isinf(f))
    {
        if (f > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
        return;
    }
    
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

// Print double conversion
void printDouble(double value)
{
    if (std::isnan(value))
    {
        std::cout << "double: nan" << std::endl;
        return;
    }
    
    if (std::isinf(value))
    {
        if (value > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
        return;
    }
    
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(std::string const & s)
{
    bool error = false;
    double value = parseToDouble(s, error);
    
    if (error)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}