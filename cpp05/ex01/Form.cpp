#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), sig(false), sign(1), execute(1){}

Form::Form(const std::string& name, int sign, int execute) : name(name),
    sig(false), sign(sign), execute(execute){
        if (sign < 1 || execute < 1)
            throw GradeTooHighException();
        else if (sign > 150 || execute > 150)
            throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name),
    sig(other.sig), sign(other.sign), execute(other.execute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other)
        sig = other.sig;
    return *this;
}

Form::~Form() {}

std::string Form::getName() const {return name;}
int Form::getSign() const {return sign;}
int Form::getExecute() const {return execute;}
bool Form::getIsSigned() const {return sig;}

std::ostream &operator<<(std::ostream &os, const Form &obj) {
    os << "Form " << obj.getName()
    << ", signed " << (obj.getIsSigned() ? "yes" : "no")
    << ", required to sign " << obj.getSign()
    << ", required to execute " << obj.getExecute();
    return os;
}


void Form::beSigned(const Bureaucrat& obj){
    if (sig){
        std::cout << name << " is already signed" << std::endl;
        return;
    }
    if (obj.getGrade() > sign)
        throw GradeTooLowException();
    sig = true;
}

