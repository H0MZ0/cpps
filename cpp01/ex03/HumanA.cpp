#include "HumanA.hpp"

HumanA::HumanA( std::string w ){
	weapon = w;
}

void	HumanA::setType( std::string n ){
	name = n;
}

void	HumanA::attack( void ){
    std::cout << name << " attacks with their " << weapon << std::endl;
}

void	HumanA::setWeapon( class Weapon ){
	weapon = Weapon::getType();
}