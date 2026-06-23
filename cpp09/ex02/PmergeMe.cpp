#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    if (this != &other) {
        this->_vCont = other._vCont;
        this->_dCont = other._dCont;
    }
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->_vCont = other._vCont;
        this->_dCont = other._dCont;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parsing(int ac, char **args) {
    for (int i = 1; i < ac; i++) {
        std::string check = args[i];
        
        if (check.empty()) {
            std::cerr << "Error" << std::endl;
            return false;
        }

        for (size_t j = 0; j < check.size(); j++) {
            if (!::isdigit(check[j])) {
                std::cerr << "Error" << std::endl;
                return false;
            }
        }

        std::stringstream ss(check);
        long num;
        ss >> num;
        if (num > 2147483647) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        
        int n = static_cast<int>(num);

        if (std::find(_vCont.begin(), _vCont.end(), n) != _vCont.end()) {
            std::cerr << "Error" << std::endl;
            return false;
        }

        _dCont.push_back(n);
        _vCont.push_back(n);
    }
    return true;
}

void PmergeMe::printBefore() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vCont.size(); i++) {
        std::cout << _vCont[i] << " ";
    }
    std::cout << std::endl;
}