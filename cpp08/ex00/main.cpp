#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    // ===== VECTOR TEST =====
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    try {
        easyfind(v, 2); // found
        std::cout << "Vector: value found" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Vector: value not found" << std::endl;
    }

    try {
        easyfind(v, 42); // not found
        std::cout << "Vector: value found" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Vector: value not found" << std::endl;
    }

    // ===== LIST TEST =====
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    try {
        easyfind(l, 20); // found
        std::cout << "List: value found" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "List: value not found" << std::endl;
    }

    try {
        easyfind(l, -1); // not found
        std::cout << "List: value found" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "List: value not found" << std::endl;
    }

    // ===== CONST CONTAINER TEST =====
    const std::vector<int> cv(v);

    try {
        easyfind(cv, 1); // found
        std::cout << "Const vector: value found" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Const vector: value not found" << std::endl;
    }

    return 0;
}
