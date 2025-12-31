#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include <fstream>

class Bureaucrat;

class AForm {
    private:
    const std::string name;
    bool sig;
    const int sign;
    const int exec;

    public:
    AForm();
    AForm(const std::string& name, int sign, int exec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string getName() const;
    int getSign() const;
    int getExecute() const;
    bool getIsSigned() const ;
    virtual void execute(Bureaucrat const & executor) const = 0;

    void beSigned(const Bureaucrat& obj);
    class GradeTooHighException : public std::exception{
        public:
        virtual const char* what() const throw(){
            return "AForm grade too high";
        }
    };

    class GradeTooLowException : public std::exception{
        public: 
        virtual const char* what() const throw(){
            return "AForm grade too low";
        }
    };

    class FormNotSignedException : public std::exception {
        public:
        virtual const char* what() const throw() {
            return "Form is not signed";
        }
    };

};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif