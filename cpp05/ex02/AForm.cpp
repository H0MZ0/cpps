#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), signGrade(150), executeGrade(150) {
    std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
    : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
    std::cout << "AForm constructor called" << std::endl;
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
    std::cout << "AForm " << name << " created with sign grade " << signGrade
              << " and execute grade " << executeGrade << std::endl;
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      signGrade(other.signGrade), executeGrade(other.executeGrade) {
    std::cout << "Default AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &other) {
    std::cout << "Default AForm copy assignment operator called" << std::endl;
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() {
    std::cout << "Default AForm destructor called" << std::endl;
}

std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecuteGrade() const { return executeGrade; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > signGrade)
        throw AForm::GradeTooLowException();
    isSigned = true;
}
const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

void AForm::execute(Bureaucrat const & executor){
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > executeGrade)
        throw GradeTooLowException();
    execute();
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
    os << "AForm " << obj.getName() << ", signed: " << (obj.getIsSigned() ? "yes" : "no")
       << ", sign grade: " << obj.getSignGrade()
       << ", exec grade: " << obj.getExecuteGrade();
    return os;
}

