#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    PmergeMe obj;
    if (!obj.parsing(ac, av))
        return 1;
        
    obj.printBefore();
    
    struct timeval start, end;    
    gettimeofday(&start, NULL);
    obj.sortVector();
    gettimeofday(&end, NULL);
    long timeVec = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    obj.sortDeque();
    gettimeofday(&end, NULL);
    long timeDeq = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
    
    obj.printAfter();    
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque  : " << timeDeq << " us" << std::endl;
    
    return 0;
}
