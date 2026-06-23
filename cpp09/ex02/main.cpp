#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    PmergeMe obj;
    if (!obj.parsing(ac, av))
        return 1;
    obj.printBefore();
    
    return 0;
}