#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat{
    private:
    const std::string name;
    int grade;

    public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    
    void incrementGrade();
    void decrementGrade();

    void executeForm(AForm const & form);

    void signForm(AForm& form);
    class GradeTooHighException : public std::exception{
        public:
        virtual const char* what() const throw(){
            return "Bureaucrat grade too high";
        }
    };

    class GradeTooLowException : public std::exception{
        public:
        virtual const char* what() const throw(){
            return "Bureaucrat grade too low";
        }
    };

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj);

#endif