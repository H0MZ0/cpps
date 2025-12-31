#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 140);
        ShrubberyCreationForm shrub("home");
        
        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;
        
        bob.signForm(shrub);
        bob.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 2: ShrubberyCreationForm - Grade too low to sign ===" << std::endl;
    try {
        Bureaucrat john("John", 150);
        ShrubberyCreationForm shrub2("garden");
        
        std::cout << john << std::endl;
        john.signForm(shrub2);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 3: ShrubberyCreationForm - Grade too low to execute ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 145);
        Bureaucrat charlie("Charlie", 140);
        ShrubberyCreationForm shrub3("park");
        
        alice.signForm(shrub3);
        charlie.executeForm(shrub3);  // Charlie can't execute (needs 137)
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 4: RobotomyRequestForm ===" << std::endl;
    try {
        Bureaucrat dave("Dave", 40);
        RobotomyRequestForm robot("Bender");
        
        std::cout << dave << std::endl;
        std::cout << robot << std::endl;
        
        dave.signForm(robot);
        dave.executeForm(robot);
        dave.executeForm(robot);  // Try again to see randomness
        dave.executeForm(robot);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 5: RobotomyRequestForm - Grade too low to sign ===" << std::endl;
    try {
        Bureaucrat eve("Eve", 80);
        RobotomyRequestForm robot2("Target1");
        
        eve.signForm(robot2);  // Eve can't sign (needs 72 or better)
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 6: RobotomyRequestForm - Grade too low to execute ===" << std::endl;
    try {
        Bureaucrat frank("Frank", 72);
        Bureaucrat george("George", 50);
        RobotomyRequestForm robot3("Target2");
        
        frank.signForm(robot3);
        george.executeForm(robot3);  // George can't execute (needs 45 or better)
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 7: PresidentialPardonForm ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 8: PresidentialPardonForm - Grade too low to sign ===" << std::endl;
    try {
        Bureaucrat harry("Harry", 30);
        PresidentialPardonForm pardon2("Zaphod");
        
        harry.signForm(pardon2);  // Harry can't sign (needs 25 or better)
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 9: PresidentialPardonForm - Grade too low to execute ===" << std::endl;
    try {
        Bureaucrat irene("Irene", 25);
        Bureaucrat jack("Jack", 10);
        PresidentialPardonForm pardon3("Ford Prefect");
        
        irene.signForm(pardon3);
        jack.executeForm(pardon3);  // Jack can't execute (needs 5 or better)
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 10: Execute without signing ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        PresidentialPardonForm pardon4("Marvin");
        
        boss.executeForm(pardon4);  // Not signed yet!
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 11: Multiple forms, one bureaucrat ===" << std::endl;
    try {
        Bureaucrat vip("VIP", 1);
        ShrubberyCreationForm s("office");
        RobotomyRequestForm r("Employee");
        PresidentialPardonForm p("Criminal");
        
        vip.signForm(s);
        vip.signForm(r);
        vip.signForm(p);
        
        vip.executeForm(s);
        vip.executeForm(r);
        vip.executeForm(p);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
