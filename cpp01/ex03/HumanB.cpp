#include "HumanB.hpp"

void	HumanB::setType( std::string n ){
	name = n;
}

void	HumanB::attack( void ){
    std::cout << name << " attacks with their " << weapon << std::endl;
}

void	HumanB::setWeapon( class Weapon ){
}