#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
	std::cout << "Default Ice constructor called!" << std::endl;
}

Ice& Ice::operator=(const Ice &other){

}

Ice::Ice(const Ice &other){

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