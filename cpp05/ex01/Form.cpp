#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), signGrade(150), executeGrade(150) {
    std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(const std::string& name, int signGrade, int executeGrade)
    : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
    std::cout << "Form constructor called" << std::endl;
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form " << name << " created with sign grade " << signGrade
              << " and execute grade " << executeGrade << std::endl;
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned),
      signGrade(other.signGrade), executeGrade(other.executeGrade) {
    std::cout << "Default Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &other) {
    std::cout << "Default Form copy assignment operator called" << std::endl;
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::~Form() {
    std::cout << "Default Form destructor called" << std::endl;
}

std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getSignGrade() const { return signGrade; }
int Form::getExecuteGrade() const { return executeGrade; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > signGrade)
        throw Form::GradeTooLowException();
    isSigned = true;
}
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
    os << "Form " << obj.getName() << ", signed: " << (obj.getIsSigned() ? "yes" : "no")
       << ", sign grade: " << obj.getSignGrade()
       << ", exec grade: " << obj.getExecuteGrade();
    return os;
}

