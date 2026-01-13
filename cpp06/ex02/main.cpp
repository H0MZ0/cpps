#include "Base.hpp"

int main() {
    std::srand(std::time(0));

    std::cout << "=== Test 1 ===" << std::endl;
    Base* p1 = generate();
    std::cout << "Pointer identification: ";
    identify(p1);
    std::cout << "Reference identification: ";
    identify(*p1);
    delete p1;

    std::cout << "\n=== Test 2 ===" << std::endl;
    Base* p2 = generate();
    std::cout << "Pointer identification: ";
    identify(p2);
    std::cout << "Reference identification: ";
    identify(*p2);
    delete p2;

    std::cout << "\n=== Test 3 ===" << std::endl;
    Base* p3 = generate();
    std::cout << "Pointer identification: ";
    identify(p3);
    std::cout << "Reference identification: ";
    identify(*p3);
    delete p3;

    return 0;
}
