#include "ScalarConverter.hpp"
#include <cstdlib>
#include <string>
#include <iostream>


bool isPseudo(const std::string &s)
{
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "-inf" ||
            s == "+inff" || s == "-inff");
}

bool isChar(const std::string &s)
{
    return (s.length() == 1 && !std::isdigit(s[0]));
}

bool isInt(const std::string &s)
{
    int i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i >= (int)s.length())
        return false;
    for (; i < (int)s.length(); i++)
        if (!std::isdigit(s[i]))
            return false;
    return true;
}

bool isDouble(const std::string &s)
{
    int i = 0;
    bool hasDot = false;

    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i >= (int)s.length())
        return false;

    for (; i < (int)s.length(); i++)
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
    return isDouble(noF);
}

void ScalarConverter::print_types(std::string const & v, int type){
    if (type == 0){
        std::cout << "ma3art" ;
    }
    if (type == 1){
        std::cout << "char: " << v << std::endl;
        std::cout << "int: " << static_cast<int>(v[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(v[0]) << std::endl;
        std::cout << "double: " << static_cast<double>(v[0]) << std::endl;
    }
    if (type == 2){
        std::cout << "char: " << "Non displayable" << std::endl;
        std::cout << "int: " << atoi(v.c_str()) << std::endl;
        std::cout << "float: " << (float)atoi(v.c_str()) << std::endl;
        std::cout << "double: " << (double)atoi(v.c_str()) << std::endl;
    }
    if (type == 3 || type == 4){
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << atoi(v.c_str()) << std::endl;

        std::string tmp = v;
        if (type == 3)
            tmp = v.substr(0, v.length() - 1);

        double d = std::atof(tmp.c_str());

        std::cout << "float: " << static_cast<float>(d) << std::endl;
        std::cout << "double: " << d << std::endl;
    }

}

void ScalarConverter::convert(std::string const & v){
    int type;
    if (isPseudo(v))
        type = 0;
    else if (isChar(v))
        type = 1;
    else if (isInt(v))
        type = 2;
    else if (isFloat(v))
        type = 3;
    else if (isDouble(v))
        type = 4;
    else
        type = 9;
    print_types(v, type);
    
}