#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdio>
#include <iostream>

class BitcoinExchange {
private:
public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange operator=(const BitcoinExchange &other);
  ~BitcoinExchange();
  void parseFile(std::string File);
};

#endif