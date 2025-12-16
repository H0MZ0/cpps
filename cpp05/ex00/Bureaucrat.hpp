#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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

    class GradeTooHighException : public std::exception{
        public:
        virtual const char* what() const throw(){
            return "GradeTooHigh";
        }
    };

    class GradeTooLowException : public std::exception{
        public:
        virtual const char* what() const throw(){
            return "GradeTooLow";
        }
    };

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj);

#endif