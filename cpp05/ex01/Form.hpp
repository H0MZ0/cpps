#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
    private:
    const std::string name;
    bool sig;
    const int sign;
    const int execute;

    public:
    Form();
    Form(const std::string& name, int sign, int execute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    std::string getName() const;
    int getSign() const;
    int getExecute() const;
    bool getIsSigned() const ;

    void beSigned(const Bureaucrat& obj);
    class GradeTooHighException : public std::exception{
        public:
        virtual const char* what() const throw(){
            return "Form grade too high";
        }
    };

    class GradeTooLowException : public std::exception{
        public:
        virtual const char* what() const throw(){
            return "Form grade too low";
        }
    };

};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif