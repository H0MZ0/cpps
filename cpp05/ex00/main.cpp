#include "Bureaucrat.hpp"

int main(){
        // Test 1: Valid creation
    Bureaucrat valid("Valid", 75);
    std::cout << valid;

    // Test 2: Too high grade in constructor
    try {
        Bureaucrat tooHigh("TooHigh", 0);
    } catch (std::exception & e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test 3: Too low grade in constructor  
    try {
        Bureaucrat tooLow("TooLow", 151);
    } catch (std::exception & e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test 4: Increment until exception
    Bureaucrat top("Top", 2);
    try {
        std::cout << top;
        top.incrementGrade();  // Should work (2→1)
        std::cout << top;
        top.incrementGrade();  // Should throw
    } catch (std::exception & e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test 5: Copy constructor
    Bureaucrat original("Original", 50);
    Bureaucrat copy(original);
    std::cout << "Original: " << original;
    std::cout << "Copy: " << copy;
    return 0;
}
