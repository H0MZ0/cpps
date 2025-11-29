#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal Deafult constructor called!" << std::endl;
}

Animal::Animal(const Animal &other){
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = other.type;
}

Animal& Animal::operator=(const Animal &other){
	std::cout << "Animal copy assignemet operator called" << std::endl;
	if (this != &other){
		this->type = other.type;
	}
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal Deafult destructor called!" << std::endl;
}


std::string Animal::getType() const{
	return type;
}

void Animal::makeSound() const{
	std::cout << type << " make sound ->" << "Animal" <<  std::endl;
}