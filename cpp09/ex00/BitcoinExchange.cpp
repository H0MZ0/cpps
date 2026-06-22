#include "BitcoinExchange.hpp"
#include <cstdio>
#include <fstream>
#include <string>

BitcoinExchange::BitcoinExchange() {
    loadDatabase();
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	if (this != &other)
        this->_database = other._database;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
	if (this != &other)
        this->_database = other._database;
	return  *this;
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase() {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string rate_str;

        if (std::getline(ss, date, ',') && std::getline(ss, rate_str))
            _database[date] = std::strtod(rate_str.c_str(), NULL);
    }
    file.close();
}
void BitcoinExchange::parseFile(char *File) {
    std::ifstream file(File);
    if (!file.is_open()) {
        std::cerr << "Error: can't open file " << File << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue; 

        std::stringstream ss(line);
        std::string date;
        char pipe;
        double value;

        if (ss >> date >> pipe >> value) {
            if (pipe != '|') {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            std::string extra;
            if (ss >> extra) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            } else if (!isValidValue(value)) {
                continue;
            } else {
                std::map<std::string, double>::iterator it = _database.lower_bound(date);
                if (it == _database.end() || it->first != date) {
                    if (it == _database.begin()) {
                        std::cerr << "Error: no valid date found before " << date << std::endl;
                        continue;
                    }
                    --it;
                }
                std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
    file.close();
}

bool BitcoinExchange::isValidValue(const double value) {
    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000){
		std::cerr << "Error: too large a number." << std::endl;
		return false;
    }
    return true;
}

bool BitcoinExchange::isValidDate(const std::string &date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    char c1, c2;
    std::stringstream ss(date);
    
    if (!(ss >> year >> c1 >> month >> c2 >> day) || c1 != '-' || c2 != '-') {
        return false;
	}

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31){
        return false;
	}
	
	return true;
}
