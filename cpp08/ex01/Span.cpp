#include "Span.hpp"

Span::Span() : _N(0), _numbers() {}

Span::Span(unsigned int N) : _N(N), _numbers() {}

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _N = other._N;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _N)
        throw std::overflow_error("Cannot add more numbers, capacity reached");
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    std::vector<int> copy(_numbers);
    std::sort(copy.begin(), copy.end());

    int minSpan = copy[1] - copy[0];

    for (size_t i = 1; i < copy.size(); i++) {
        int diff = copy[i] - copy[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }

    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    std::vector<int>::const_iterator mn = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator mx = std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(*mx - *mn);
}
