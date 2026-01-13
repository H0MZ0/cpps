#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    std::cout << "=== Test 1: Creating valid Forms ===" << std::endl;
    try {
        Form formA("FormA", 50, 25);
        std::cout << formA << std::endl;
        
        Form formB("FormB", 1, 1);
        std::cout << formB << std::endl;
        
        Form formC("FormC", 150, 150);
        std::cout << formC << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 2: Form with invalid grade (too high) ===" << std::endl;
    try {
        Form invalid("Invalid", 0, 50);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 3: Form with invalid grade (too low) ===" << std::endl;
    try {
        Form invalid("Invalid", 50, 151);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 4: Bureaucrat signing form successfully ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 30);
        Form form("Tax Form", 50, 25);
        std::cout << "Before: " << form << std::endl;
        bob.signForm(form);
        std::cout << "After: " << form << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 5: Bureaucrat can't sign (grade too low) ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 100);
        Form vipForm("VIP Form", 50, 25);
        std::cout << intern << std::endl;
        std::cout << vipForm << std::endl;
        intern.signForm(vipForm);
        std::cout << vipForm << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 6: Multiple bureaucrats signing forms ===" << std::endl;
    try {
        Bureaucrat ceo("CEO", 1);
        Bureaucrat manager("Manager", 50);
        Bureaucrat employee("Employee", 100);
        
        Form easyForm("Easy Form", 100, 100);
        Form mediumForm("Medium Form", 50, 50);
        Form hardForm("Hard Form", 1, 1);
        
        employee.signForm(easyForm);
        employee.signForm(mediumForm);
        employee.signForm(hardForm);
        
        std::cout << std::endl;
        manager.signForm(mediumForm);
        manager.signForm(hardForm);
        
        std::cout << std::endl;
        ceo.signForm(hardForm);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}