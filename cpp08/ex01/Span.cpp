#include "Span.hpp"

Span::Span() : _N(0), _numbers() {}

Span::Span(unsigned int N) : _N(N), _numbers() {
    if (N == 0)
        throw std::invalid_argument("N must be greater than 0");
}

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

int Span::shortestSpan() const {
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

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    int min = _numbers[0];
    int max = _numbers[0];

    for (size_t i = 1; i < _numbers.size(); i++) {
        if (_numbers[i] < min)
            min = _numbers[i];
        if (_numbers[i] > max)
            max = _numbers[i];
    }

    return max - min;
}
