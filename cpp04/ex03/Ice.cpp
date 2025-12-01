#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice"){
	std::cout << "Default Ice constructor called!" << std::endl;
}

Ice& Ice::operator=(const Ice &other){
	std::cout << "Ice copy assignemet operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Ice::Ice(const Ice &other) : AMateria(other){
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice(){
	std::cout << "Default Ice destructor called!" << std::endl;
}

AMateria* Ice::clone() const{
	return new Ice();
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}