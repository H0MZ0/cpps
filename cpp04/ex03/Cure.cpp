#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
	std::cout << "Default Cure constructor called!" << std::endl;

}

Cure& Cure::operator=(const Cure &other){

}

Cure::Cure(const Cure &other){

}

Cure::~Cure(){
	std::cout << "Default Cure destructor called!" << std::endl;
}

AMateria* Cure::clone() const{
	return new Cure();
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}