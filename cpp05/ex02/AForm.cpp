#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), sig(false), sign(1), exec(1){}

AForm::AForm(const std::string& name, int sign, int exec) : name(name),
    sig(false), sign(sign), exec(exec){
        if (sign < 1 || exec < 1)
            throw GradeTooHighException();
        else if (sign > 150 || exec > 150)
            throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name),
    sig(other.sig), sign(other.sign), exec(other.exec) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        sig = other.sig;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {return name;}
int AForm::getSign() const {return sign;}
int AForm::getExecute() const {return exec;}
bool AForm::getIsSigned() const {return sig;}

std::ostream &operator<<(std::ostream &os, const AForm &obj) {
    os << "AForm " << obj.getName()
    << ", signed " << (obj.getIsSigned() ? "yes" : "no")
    << ", required to sign " << obj.getSign()
    << ", required to execute " << obj.getExecute();
    return os;
}


void AForm::beSigned(const Bureaucrat& obj){
    if (sig){
        std::cout << name << " is already signed" << std::endl;
        return;
    }
    if (obj.getGrade() > sign)
        throw GradeTooLowException();
    sig = true;
}

