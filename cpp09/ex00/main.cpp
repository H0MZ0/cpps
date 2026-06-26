#include "BitcoinExchange.hpp"
#include <exception>


int main(int ac, char **av){
    if (ac != 2){
        std::cerr << "Error: Need a file" << std::endl;
        return 1;
    }

    try{
        BitcoinExchange btc;
        btc.parseFile(av[1]);
    } catch (std::exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}