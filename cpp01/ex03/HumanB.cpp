#include "HumanB.hpp"

HumanB::HumanB( std::string n ) : name(n), weapon(weapon){}

void	HumanB::attack( void ){
    std::cout << name << " attacks with their " <<  weapon.getType() << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon ){
	weapon.setType("no weapon");
}
