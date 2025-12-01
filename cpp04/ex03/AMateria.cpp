#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type) : type(type){
	std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other){
	std::cout << "AMateria copy assignemet operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

AMateria::AMateria(const AMateria &other){
	std::cout << "AMateria copy constructor called" << std::endl;
	this->type = other.type;
}

std::string const & AMateria::getType() const {return type;}

void AMateria::use(ICharacter& target){
	std::cout << "AMateria " << target.getName() << " used" << std::endl;
}

AMateria::~AMateria(){
	std::cout << "AMateria default destructor called" << std::endl;
}