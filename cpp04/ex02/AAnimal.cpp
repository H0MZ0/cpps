#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal Deafult constructor called!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other){
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->type = other.type;
}

AAnimal& AAnimal::operator=(const AAnimal &other){
	std::cout << "AAnimal copy assignemet operator called" << std::endl;
	if (this != &other){
		this->type = other.type;
	}
	return *this;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal Deafult destructor called!" << std::endl;
}

std::string AAnimal::getType() const{
	return type;
}
