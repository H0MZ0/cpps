#include "Form.hpp"

Form::Form() : name("Default"), sign(1), execute(1){}

Form::Form(std::string name, int sign, int execute){

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



