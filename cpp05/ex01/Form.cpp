#include "Form.hpp"
// #include "Bureaucrat.hpp"

Form::Form() : name("Default"), sign(1), execute(1){}

Form::Form(std::string name, int sign, int execute) : name(name), sig(false), sign(sign), execute(execute){
    std::cout << "Form Constructor called" << std::endl;
}

Form& Form::operator=(const Form& other){
    (void)other;
    return *this;
}

Form& Form::operator=(const Form& other){
    (void)other;
    return *this;
}


Form::~Form() {}

std::string Form::getName() const {return name;}
int Form::getSign() const {return sign;}
int Form::getExecute() const {return execute;}
bool Form::getIsSigned() const {return sig;}

std::ostream &operator<<(std::ostream &os, const Form &obj) {
    os << obj.getName() << " required " << obj.getSign() << " to sign, "
    << "and " << obj.getExecute() << " to execute" << std::endl << ", and he's";
    ///////////// 
    return os;
}


void Form::GradeTooHighException(){
    std::cout << name << " GradeTooHigh" << std::endl; 
}
void Form::GradeTooLowException(){
    std::cout << name << " GradeTooLow" << std::endl; 
}

void Form::beSigned(const Bureaucrat& obj){
    if (sign <= obj.getGrade() && obj.getGrade() >= 1)
        sig = true;
    if (obj.getGrade() < 1){
        sig = false;
        GradeTooHighException();
    }
    else if (obj.getGrade() > 150){
        sig = false;
        GradeTooLowException();
    }
    else
        std::cout << name << " grade " << obj.getGrade()
        << " cannot sign, cause of sign required is ->" << sign << std::endl;
        
}