#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main() {
    std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 130);
        ShrubberyCreationForm shrub("home");
        
        bob.signForm(shrub);
        bob.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 2: RobotomyRequestForm ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robot("Bender");
        
        alice.signForm(robot);
        alice.executeForm(robot);
        alice.executeForm(robot); // Try again to see randomness
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 4: Execute without signing ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 1);
        PresidentialPardonForm pardon("Ford");
        
        intern.executeForm(pardon); // Should fail - not signed
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 5: Execute with insufficient grade ===" << std::endl;
    try {
        Bureaucrat lowly("Lowly", 50);
        PresidentialPardonForm pardon("Zaphod");
        
        Bureaucrat high("High", 1);
        high.signForm(pardon);
        lowly.executeForm(pardon); // Should fail - grade too low
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}