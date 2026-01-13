#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150){
    std::cout << "Default Bureaucrat contructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade){
    std::cout << "Bureaucrat constuctor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat " << name << " set grade to ->{" << grade << "}" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name){
    std::cout << "Default Bureaucrat copy contructor called" << std::endl;
    grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
    std::cout << "Default Bureaucrat copy assignemet operator called" << std::endl;
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Default destrutctor called" << std::endl;
}

std::string Bureaucrat::getName() const {return name;}

int Bureaucrat::getGrade() const {return grade;}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj){
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}
