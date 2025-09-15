#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(4, 0);
    Point c(0, 3);

    Point p1(1, 1); // inside
    Point p2(5, 1); // outside
    Point p3(0, 0); // on vertex
    Point p4(2, 0); // on edge

    std::cout << "P1 inside? " << (bsp(a, b, c, p1) ? "Yes" : "No") << std::endl;
    std::cout << "P2 inside? " << (bsp(a, b, c, p2) ? "Yes" : "No") << std::endl;
    std::cout << "P3 inside? " << (bsp(a, b, c, p3) ? "Yes" : "No") << std::endl;
    std::cout << "P4 inside? " << (bsp(a, b, c, p4) ? "Yes" : "No") << std::endl;

    return 0;
}
