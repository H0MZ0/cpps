#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
    private:
    const std::string name;
    bool sig;
    const int sign;
    const int execute;

    public:
    Form();
    Form(std::string name, int sign, int execute);
    Form& operator=(const Form& other);
    ~Form();

    std::string getName() const;
    int getSign() const;
    int getExecute() const;
    bool getIsSigned() const ;

    void beSigned(const Bureaucrat& obj);
    void GradeTooHighException();
    void GradeTooLowException();
    // void ExceptionTypes();
};

std::ostream &operator<<(std::ostream &os, const Form &obj);