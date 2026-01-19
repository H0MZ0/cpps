#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"


class Intern {
private:
    AForm* createShrubberyCreation(std::string target);
    AForm* createRobotomyRequest(std::string target);
    AForm* createPresidentialPardon(std::string target);

    
public:
    Intern();
    Intern(const Intern &other);
    Intern& operator=(const Intern &other);
    ~Intern();
    
    AForm* makeForm(std::string formName, std::string target);
};

#endif