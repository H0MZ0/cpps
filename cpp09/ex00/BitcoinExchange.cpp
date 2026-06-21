#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    if (this != &other){

    }
}
BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange& other){
    if (this != &other){
        
    }
    return  *this;
}
BitcoinExchange::~BitcoinExchange() {}
void parseFile(std::string File){
    std::File* file = 
}