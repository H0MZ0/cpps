#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade) : grade(grade){
    std::cout << "Bureaucrat Constructor " << name << " init with " << grade << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return os;
}

std::string Bureaucrat::getName() const {return name;}

int Bureaucrat::getGrade() const {return grade;}

void Bureaucrat::GradeTooHighException(){
    std::cout << "Bureaucrat " << name << " GradeTooHigh ->" << grade << std::endl;
}

void Bureaucrat::GradeTooLowException(){
    std::cout << "Bureaucrat " << name << " GradeTooLow ->" << grade << std::endl;
}


Bureaucrat& Bureaucrat::operator++() {
    if (grade > 1 && grade <= 150)
        grade--;
    else
        std::cout << "Bureaucrat " << name << " can't make grade higher" << std::endl;
    return *this;
}

Bureaucrat& Bureaucrat::operator--(){
    if (grade < 150 && grade >= 1)
        grade++;
    else
        std::cout << "Bureaucrat " << name << " can't make grade lower" << std::endl;
    return *this;
}
