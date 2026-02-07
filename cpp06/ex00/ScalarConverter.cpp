#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal)
{
    double val;

    if (literal == "nan" || literal == "nanf")
        val = NAN;
    else if (literal == "inf" || literal == "+inf" ||
             literal == "inff" || literal == "+inff")
        val = INFINITY;
    else if (literal == "-inf" || literal == "-inff")
        val = -INFINITY;

    else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' )
        val = static_cast<double>(literal[1]);

    else if (literal.length() == 1 &&
             std::isprint(literal[0]) &&
             !std::isdigit(literal[0]))
        val = static_cast<double>(literal[0]);

    else
    {
        char *end = NULL;
        val = std::strtod(literal.c_str(), &end);

        if (*end != '\0' && !(end[0] == 'f' && end[1] == '\0'))
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            return;
        }
    }

    std::cout << "char: ";
    if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127)
        std::cout << "impossible";
    else if (!std::isprint(static_cast<char>(val)))
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(val) << "'";
    std::cout << "\n";

    std::cout << "int: ";
    if (std::isnan(val) || std::isinf(val) ||
        val < std::numeric_limits<int>::min() ||
        val > std::numeric_limits<int>::max())
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(val);
    std::cout << "\n";

    std::cout << "float: " << std::fixed << std::setprecision(1);
    std::cout << static_cast<float>(val) << "f\n";

    std::cout << "double: " << std::fixed << std::setprecision(1);
    std::cout << val << "\n";
}
