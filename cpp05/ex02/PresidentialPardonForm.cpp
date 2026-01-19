#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute() const{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
