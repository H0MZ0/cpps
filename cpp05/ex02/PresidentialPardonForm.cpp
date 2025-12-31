#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), target("Default"){
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
    AForm("Presidential Pardon", 25, 5), target(target){

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
    AForm(other) , target(other.target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other){
        target = other.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > 5)
        throw GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
