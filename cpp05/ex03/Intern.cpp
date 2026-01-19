#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other){
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}

Intern& Intern::operator=(const Intern &other){
    std::cout << "Intern copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern(){
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::createShrubberyCreation(std::string target){
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createPresidentialPardon(std::string target){
    return new PresidentialPardonForm(target);
}


AForm* Intern::createRobotomyRequest(std::string target){
    return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target){
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm *((Intern::*formCreators[3])(std::string)) = {
        &Intern::createShrubberyCreation,
        &Intern::createRobotomyRequest,
        &Intern::createPresidentialPardon
    };

    for (int i = 0; i < 3; i++){
        if (formName == formNames[i]){
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*formCreators[i])(target));
        }

    }
    std::cout << "Intern cannot create " << formName
              << " because it doesn't exist" << std::endl;
    return NULL;
}

