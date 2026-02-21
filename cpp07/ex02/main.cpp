
#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    // Empty array
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;

    // Array with size
    Array<int> b(5);
    std::cout << "b.size() = " << b.size() << std::endl;

    for (unsigned int i = 0; i < b.size(); i++)
        b[i] = i * 10;

    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;

    // Copy constructor
    Array<int> c(b);
    c[0] = 999;

    std::cout << "After copy modification:" << std::endl;
    std::cout << "b[0] = " << b[0] << std::endl;
    std::cout << "c[0] = " << c[0] << std::endl;

    // Assignment operator
    Array<int> d;
    d = b;
    d[1] = 777;

    std::cout << "After assignment modification:" << std::endl;
    std::cout << "b[1] = " << b[1] << std::endl;
    std::cout << "d[1] = " << d[1] << std::endl;

    // Different type
    Array<std::string> s(2);
    s[0] = "hello";
    s[1] = "world";
    std::cout << s[0] << " " << s[1] << std::endl;

    // Out of bounds test
    try {
        std::cout << b[100] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught" << std::endl;
    }

    return 0;
}
