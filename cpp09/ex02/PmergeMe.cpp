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

        size_t j = 0;
        if (check[j] == '+') {
            j++;
            if (check.size() == 1) {
                std::cerr << "Error" << std::endl;
                return false;
            }
        }

        for (; j < check.size(); j++) {
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
    for (size_t i = 0; i < _vCont.size(); i++) std::cout << _vCont[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printAfter() const {
    std::cout << "After:  ";
    for (size_t i = 0; i < _vCont.size(); i++) std::cout << _vCont[i] << " ";
    std::cout << std::endl;
}

size_t getJacobsthalNumber(size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return getJacobsthalNumber(n - 1) + 2 * getJacobsthalNumber(n - 2);
}

void recursiveSortVector(std::vector<int>& vec) {
    if (vec.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = (vec.size() % 2 != 0);

    for (size_t i = 0; i < vec.size() - 1; i += 2) {
        if (vec[i] < vec[i + 1])
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
        else
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    }
    if (hasStraggler) straggler = vec.back();

    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++) largerElements.push_back(pairs[i].first);
    
    recursiveSortVector(largerElements);

    std::vector<int> mainChain = largerElements;
    std::vector<int> pend;

    for (size_t i = 0; i < mainChain.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (mainChain[i] == pairs[j].first) {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }

    if (!pend.empty()) mainChain.insert(mainChain.begin(), pend[0]);

    size_t jacobIndex = 3;
    size_t insertedCount = 1;
    while (insertedCount < pend.size()) {
        size_t targetJacob = getJacobsthalNumber(jacobIndex);
        if (targetJacob > pend.size()) targetJacob = pend.size();

        for (size_t i = targetJacob - 1; i >= insertedCount; i--) {
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
            mainChain.insert(it, pend[i]);
        }
        insertedCount = targetJacob;
        jacobIndex++;
    }

    if (hasStraggler) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }
    vec = mainChain;
}

void PmergeMe::sortVector() {
    recursiveSortVector(this->_vCont);
}

void recursiveSortDeque(std::deque<int>& deq) {
    if (deq.size() <= 1) return;

    std::deque<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = (deq.size() % 2 != 0);

    for (size_t i = 0; i < deq.size() - 1; i += 2) {
        if (deq[i] < deq[i + 1])
            pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
        else
            pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
    }
    if (hasStraggler) straggler = deq.back();

    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++) largerElements.push_back(pairs[i].first);
    
    recursiveSortDeque(largerElements);

    std::deque<int> mainChain = largerElements;
    std::deque<int> pend;

    for (size_t i = 0; i < mainChain.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (mainChain[i] == pairs[j].first) {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }

    if (!pend.empty()) mainChain.push_front(pend[0]);

    size_t jacobIndex = 3;
    size_t insertedCount = 1;
    while (insertedCount < pend.size()) {
        size_t targetJacob = getJacobsthalNumber(jacobIndex);
        if (targetJacob > pend.size()) targetJacob = pend.size();

        for (size_t i = targetJacob - 1; i >= insertedCount; i--) {
            std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
            mainChain.insert(it, pend[i]);
        }
        insertedCount = targetJacob;
        jacobIndex++;
    }

    if (hasStraggler) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }
    deq = mainChain;
}

void PmergeMe::sortDeque() {
    recursiveSortDeque(this->_dCont);
}
