#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
    private:
    AForm* createShrubberyCreationForm(std::string target);
    AForm* createRobotomyRequestForm(std::string target);
    AForm* createPresidentialPardonForm(std::string target);

    public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(std::string name, std::string form);


};


#endif