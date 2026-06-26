#include "BitcoinExchange.hpp"

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
        throw std::runtime_error("could not open database file.");
    }
    
    std::string line;
    if (!std::getline(file, line) || line.empty()) {
        file.close();
        throw std::runtime_error("database file is empty.");
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string rate_str;

        if (std::getline(ss, date, ',') && std::getline(ss, rate_str))
            _database[date] = std::strtod(rate_str.c_str(), NULL);
    }
    file.close();

    if (_database.empty()) {
        throw std::runtime_error("database has no valid content.");
    }
}

void BitcoinExchange::parseFile(char *File) {
    std::ifstream file(File);
    if (!file.is_open()) {
        throw std::runtime_error("could not open input file.");
    }
    
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        size_t pipe_pos = line.find('|');
        if (pipe_pos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date_str = line.substr(0, pipe_pos);
        std::string val_str = line.substr(pipe_pos + 1);

        if (!date_str.empty() && date_str[date_str.length() - 1] == ' ')
            date_str = date_str.substr(0, date_str.length() - 1);
        if (!val_str.empty() && val_str[0] == ' ')
            val_str = val_str.substr(1);

        if (!isValidDate(date_str)) {
            std::cerr << "Error: bad input => " << date_str << std::endl;
            continue;
        }

        char* endptr;
        double value = std::strtod(val_str.c_str(), &endptr);
        if (*endptr != '\0' && !isspace(*endptr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidValue(value)) {
            continue;
        }

        std::map<std::string, double>::iterator it = _database.lower_bound(date_str);
        if (it == _database.end() || it->first != date_str) {
            if (it == _database.begin()) {
                std::cerr << "Error: no valid date found before " << date_str << std::endl;
                continue;
            }
            --it;
        }
        std::cout << date_str << " => " << value << " = " << (value * it->second) << std::endl;
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
    
    if (!(ss >> year >> c1 >> month >> c2 >> day) || c1 != '-' || c2 != '-')
        return false;

    if (year < 2009 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;
    
    return true;
}
