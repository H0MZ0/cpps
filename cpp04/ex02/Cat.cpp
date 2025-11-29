#include "Cat.hpp"

Cat::Cat() : sound("Meow"){
	std::cout << "Cat Deafult constructor called!" << std::endl;
	type = "Cat";
	brain = new Brain;
}

Cat::Cat(const Cat &other) : Animal(other){
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
	this->type = "Cat";
	this->sound = other.sound;
}

Cat& Cat::operator=(const Cat &other){
	std::cout << "Cat copy assignemet operator called" << std::endl;
	if (this != &other){
		delete brain;
		brain = new Brain(*other.brain);
		this->type = "Cat";
		this->sound = other.sound;
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat Deafult destructor called!" << std::endl;
	delete brain;
}

std::string Cat::getType() const{
	return type;
}

void Cat::makeSound() const{
	std::cout << type << " make sound ->" << sound <<  std::endl;
}