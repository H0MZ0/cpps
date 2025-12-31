#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
    AForm("Robotomy Request", 72, 45), target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other){
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > 45)
        throw GradeTooLowException();
    std::cout << target << "  has been robotomized successfully" << std::endl;
}
