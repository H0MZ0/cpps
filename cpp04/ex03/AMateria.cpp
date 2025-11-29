#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type){
	std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other){

}

AMateria::AMateria(const AMateria &other){

}

std::string const & AMateria::getType() const {return type;}

void AMateria::use(ICharacter& target){
	std::cout << "AMateria " << target.getName() << " used" << std::endl;
}
