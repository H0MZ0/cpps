#pragma once

#include <iostream>

class Bureaucrat{
    private:
    const std::string name;
    int grade;

    public:
    Bureaucrat(int grade);
    std::string getName() const;
    int getGrade() const;
    
    void GradeTooHighException();
    void GradeTooLowException();
    
    Bureaucrat& operator++();
    Bureaucrat& operator--();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj);