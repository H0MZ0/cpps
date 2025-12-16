#pragma once

#include <iostream>

class Bureaucrat{
    private:
    const std::string name;
    int grade;

    public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    
    void GradeTooHighException();
    void GradeTooLowException();
    
    Bureaucrat operator++(int);
    Bureaucrat operator--(int);

    class GradeTooHighException : public std::exception{

    };

    class GradeTooLowException : public std::exception{

    };

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj);