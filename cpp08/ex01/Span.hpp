#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _numbers;
        Span();

    public:
        Span(const Span& other);
        Span& operator=(const Span& other);
        Span(unsigned int N);
        ~Span();
        
        template <typename It>
        void            addNumber(It first, It last);
        void            addNumber(int number);
        unsigned int    shortestSpan() const;
        unsigned int    longestSpan() const;
};

template <typename It>
void Span::addNumber(It first, It last) {
    It it = first;
    std::size_t count = static_cast<std::size_t>(std::distance(it, last));
    if (count > _N - _numbers.size())
        throw std::overflow_error("Span capacity exceeded");
    _numbers.insert(_numbers.end(), first, last);
}

#endif