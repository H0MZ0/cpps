#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "===   TESTING INTERN - EX03         ===" << std::endl;
    std::cout << "========================================\n" << std::endl;

    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    Bureaucrat manager("Manager", 50);
    Bureaucrat employee("Employee", 140);

    std::cout << "=== Test 1: Creating Shrubbery Creation Form ===" << std::endl;
    AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form1) {
        std::cout << *form1 << std::endl;
        boss.signForm(*form1);
        employee.executeForm(*form1);
        delete form1;
    }
    std::cout << std::endl;

    std::cout << "=== Test 2: Creating Robotomy Request Form ===" << std::endl;
    AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form2) {
        std::cout << *form2 << std::endl;
        manager.signForm(*form2);
        manager.executeForm(*form2);
        manager.executeForm(*form2); // Try again to see randomness
        delete form2;
    }
    std::cout << std::endl;

    std::cout << "=== Test 3: Creating Presidential Pardon Form ===" << std::endl;
    AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (form3) {
        std::cout << *form3 << std::endl;
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }
    std::cout << std::endl;

    std::cout << "=== Test 4: Invalid Form Name ===" << std::endl;
    AForm* invalidForm = someRandomIntern.makeForm("tax evasion form", "Me");
    if (invalidForm) {
        std::cout << "Form created (should not happen)" << std::endl;
        delete invalidForm;
    } else {
        std::cout << "Form was not created (as expected)" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 5: Another Invalid Form ===" << std::endl;
    AForm* invalidForm2 = someRandomIntern.makeForm("random stuff", "Target");
    if (invalidForm2) {
        delete invalidForm2;
    }
    std::cout << std::endl;

    std::cout << "=== Test 6: Multiple Forms from Same Intern ===" << std::endl;
    AForm* shrub1 = someRandomIntern.makeForm("shrubbery creation", "Home");
    AForm* shrub2 = someRandomIntern.makeForm("shrubbery creation", "Office");
    AForm* robot1 = someRandomIntern.makeForm("robotomy request", "Target1");
    
    if (shrub1 && shrub2 && robot1) {
        boss.signForm(*shrub1);
        boss.signForm(*shrub2);
        boss.signForm(*robot1);
        
        boss.executeForm(*shrub1);
        boss.executeForm(*shrub2);
        boss.executeForm(*robot1);
        
        delete shrub1;
        delete shrub2;
        delete robot1;
    }
    std::cout << std::endl;

    std::cout << "=== Test 7: Test with Insufficient Grades ===" << std::endl;
    AForm* hardForm = someRandomIntern.makeForm("presidential pardon", "Prisoner");
    if (hardForm) {
        employee.signForm(*hardForm); // Should fail - grade too low
        employee.executeForm(*hardForm); // Should fail - not signed
        delete hardForm;
    }
    std::cout << std::endl;

    std::cout << "========================================" << std::endl;
    std::cout << "===   ALL TESTS COMPLETED           ===" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}