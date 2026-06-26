#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <sstream>
#include <cstdio>
#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <exception>

class BitcoinExchange {
    private:
    std::map<std::string , double> _database;
    void loadDatabase(); 
    bool isValidDate(const std::string &date);
    bool isValidValue(const double value);


    public:
      BitcoinExchange();
      BitcoinExchange(const BitcoinExchange &other);
      BitcoinExchange& operator=(const BitcoinExchange &other);
      ~BitcoinExchange();
      void parseFile(char *File);
};

#endif