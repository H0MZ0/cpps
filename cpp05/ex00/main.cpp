#include "Bureaucrat.hpp"

int main(){
    std::cout << "=== Test 1: Creating valid bureaucrats ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;
        
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        
        Bureaucrat charlie("Charlie", 150);
        std::cout << charlie << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 2: Grade too high (0) ===" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 0);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 3: Grade too low (151) ===" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 151);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 4: Increment grade ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
        bob.incrementGrade(); // Should throw
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 5: Decrement grade ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 149);
        std::cout << alice << std::endl;
        alice.decrementGrade();
        std::cout << "After decrement: " << alice << std::endl;
        alice.decrementGrade(); // Should throw
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
