#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;

    public:
        AForm();
        AForm(const std::string& name, int signGrade, int executeGrade);
        AForm(const AForm &other);
        AForm& operator=(const AForm &other);
        virtual ~AForm();

        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(const Bureaucrat& bureaucrat);

        virtual void execute() const = 0;
        void execute(Bureaucrat const & executor);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        
        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif