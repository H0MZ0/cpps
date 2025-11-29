#include "Dog.hpp"

Dog::Dog() : sound("Bark"){
	std::cout << "Dog Deafult constructor called!" << std::endl;
	type = "Dog";
	brain = new Brain;
}

Dog::Dog(const Dog &other) : Animal(other){
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
	this->sound = other.sound;
	this->type = "Dog";
}

Dog& Dog::operator=(const Dog &other){
	std::cout << "Dog copy assignemet operator called" << std::endl;
	if (this != &other){
		delete brain;
		brain = new Brain(*other.brain);
		this->sound = other.sound;
		this->type = "Dog";
	}
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog Deafult destructor called!" << std::endl;
	delete brain;
}


std::string Dog::getType() const{
	return type;
}

void Dog::makeSound() const{
	std::cout << type << " make sound ->" << sound <<  std::endl;
}
