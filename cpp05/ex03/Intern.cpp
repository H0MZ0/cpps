#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {(void)other;}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string form){
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*formCreators[3])(std::string) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

    for (int i = 0; i < 3; ++i) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << " form." << std::endl;
            return (this->*formCreators[i])(form);
        }
    }

    std::cout << "Intern could not find the form: " << name << std::endl;
    return NULL;
}
