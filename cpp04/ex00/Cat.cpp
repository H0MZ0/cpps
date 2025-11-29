#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat Deafult constructor called!" << std::endl;
	type = "Cat";
	sound = "Meow";
}

Cat::Cat(const Cat &other){
	(void)other;
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = "Cat";
}

Cat& Cat::operator=(const Cat &other){
	std::cout << "Cat copy assignemet operator called" << std::endl;
	if (this != &other){
		this->type = "Cat";
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat Deafult destructor called!" << std::endl;
}

std::string Cat::getType() const{
	return type;
}

void Cat::makeSound() const{
	std::cout << type << " make sound ->" << sound <<  std::endl;
}