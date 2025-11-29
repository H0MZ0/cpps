#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog Deafult constructor called!" << std::endl;
	sound = "Bark";
	type = "Dog";
}

Dog::Dog(const Dog &other){
	(void)other;
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = type;
}

Dog& Dog::operator=(const Dog &other){
	std::cout << "Dog copy assignemet operator called" << std::endl;
	if (this != &other){
		this->type = other.type;
	}
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog Deafult destructor called!" << std::endl;
}


std::string Dog::getType() const{
	return type;
}

void Dog::makeSound() const{
	std::cout << type << " make sound ->" << sound <<  std::endl;
}
