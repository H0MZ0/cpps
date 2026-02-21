#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
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
        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;
};


#endif