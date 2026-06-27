#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    PmergeMe obj;
    
    struct timeval start, end;    
    
    gettimeofday(&start, NULL);
    PmergeMe objVec;
    if (!objVec.parsing(ac, av))
        return 1;
    objVec.sortVector();
    gettimeofday(&end, NULL);
    long timeVec = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    PmergeMe objDeq;
    if (!objDeq.parsing(ac, av))
        return 1;
    objDeq.sortDeque();
    gettimeofday(&end, NULL);
    long timeDeq = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
    
    objVec.printBefore();
    objVec.printAfter();
    
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque  : " << timeDeq << " us" << std::endl;
    
    return 0;
}