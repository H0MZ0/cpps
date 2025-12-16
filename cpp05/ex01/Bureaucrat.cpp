#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
    std::cout << "Bureaucrat Constructor " << name << " init with " << grade << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return os;
}

std::string Bureaucrat::getName() const {return name;}

int Bureaucrat::getGrade() const {return grade;}

Bureaucrat Bureaucrat::operator++(int) {
    if (grade > 1 && grade <= 150)
        this->grade--;
    else
        Bureaucrat::GradeTooHighException();
    return *this;
}

Bureaucrat Bureaucrat::operator--(int){
    if (grade < 150 && grade >= 1)
        this->grade++;
    else
        Bureaucrat::GradeTooLowException();
    return *this;
}

void Bureaucrat::GradeTooHighException(){
    std::cout << name << " GradeTooHigh" << std::endl; 
}
void Bureaucrat::GradeTooLowException(){
    std::cout << name << " GradeTooLow" << std::endl; 
}

void Bureaucrat::ExceptionTypes(){
    if (grade > 150)
        GradeTooHighException();
    else if (grade  < 0)
        GradeTooLowException();
    else
        std::cout << name << " grade " << grade << std::endl;
}

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
    std::cout << "Bureaucrat Constructor " << name << " init with " << grade << std::endl;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if (this != &other)
        grade = other.grade;
    return *this;
}

void Bureaucrat::signForm(const Bureaucrat& obj){
    Form::beSigned(obj);
    if (Form::getIsSigned())
        std::cout << obj.getName() << " signed " << Form::getName() << std::endl;
    else if (Form::getIsSigned() == false)
        std::cout << obj.getName() <<  " couldn’t sign " << Form::getName() << " because <reason>" << std::endl;
    //////////////
    else
        std::cout << "Their is a problem in SignForm" << std::endl; 
}
