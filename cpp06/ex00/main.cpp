#include "ScalarConverter.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cerr << "no valid inp" << std::endl;
        return 1;
    }
    (void)ac;
    std::string v = av[1];
    ScalarConverter::convert(v);
    return 0;
}