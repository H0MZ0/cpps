#include "BitcoinExchange.hpp"


int main(int ac, char **av){
    if (ac != 2){
        std::cerr << "Error: Need a file" << std::endl;
        return 1;
    }

    parseFile(av[1]);

}