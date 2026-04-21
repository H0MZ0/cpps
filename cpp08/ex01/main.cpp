#include "Span.hpp"

int main()
{
    std::cout << "Subject test:" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Big Vector test:" << std::endl;
    try {
        std::vector<int> v;
        for (int i = 0; i < 10000; ++i)
            v.push_back(i);
        Span big(10000);
        big.addNumber(v.begin(), v.end());
        std::cout << big.shortestSpan() << std::endl;
        std::cout << big.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Empty span exception test:" << std::endl;
    try {
        Span empty(5);
        std::cout << empty.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Expected error: " << e.what() << std::endl;
    }

    std::cout << "Single element exception test:" << std::endl;
    try {
        Span one(5);
        one.addNumber(42);
        std::cout << one.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Expected error: " << e.what() << std::endl;
    }

    std::cout << "Single add overflow test:" << std::endl;
    try {
        Span small(1);
        small.addNumber(3);
        small.addNumber(4);
    } catch (const std::exception &e) {
        std::cout << "Expected overflow: " << e.what() << std::endl;
    }

    std::cout << "Range overflow test:" << std::endl;
    try {
        std::vector<int> values;
        values.push_back(10);
        values.push_back(20);
        values.push_back(30);

        Span limited(2);
        limited.addNumber(values.begin(), values.end());
    } catch (const std::exception &e) {
        std::cout << "Expected overflow: " << e.what() << std::endl;
    }

    std::cout << "Duplicate values test:" << std::endl;
    try {
        Span dup(4);
        dup.addNumber(5);
        dup.addNumber(5);
        dup.addNumber(10);
        dup.addNumber(20);
        std::cout << dup.shortestSpan() << std::endl;
        std::cout << dup.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
