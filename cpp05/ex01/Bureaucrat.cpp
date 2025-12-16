#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return os;
}

std::string Bureaucrat::getName() const {return name;}
int Bureaucrat::getGrade() const {return grade;}

void Bureaucrat::incrementGrade() {
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}



void Bureaucrat::signForm(Form& form) {
    try{
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e){
        std::cout << name <<  " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}