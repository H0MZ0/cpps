#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <sys/time.h>
#include <iomanip>


class PmergeMe {
private:
    std::deque<int> _dCont;
    std::vector<int> _vCont;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    bool parsing(int ac, char **args);
    void printBefore() const;

    void sortVector();
    void sortDeque();
    void printAfter() const;
};

#endif