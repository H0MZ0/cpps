#include "Bureaucrat.hpp"

int main(){
    try {
    Form f1("Tax Form", 50, 25);
    std::cout << f1 << std::endl;
    
    Bureaucrat john("John", 30);
    john.signForm(f1);  // Should succeed
    std::cout << f1 << std::endl;
    
    Bureaucrat bob("Bob", 100);
    bob.signForm(f1);  // Should fail - already signed or grade too low
    } catch (std::exception & e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
