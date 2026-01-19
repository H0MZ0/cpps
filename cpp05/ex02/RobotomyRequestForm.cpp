#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("Robotomy Request", 72, 45), target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute() const {
    std::cout << "* BZZZZZ DRRRRRR DRILLING NOISES *" << std::endl;

    static bool seeded = false;
    if (!seeded){
        std::srand(std::time(NULL));
        seeded = true;
    }

    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy on " << target << " failed!" << std::endl;
}