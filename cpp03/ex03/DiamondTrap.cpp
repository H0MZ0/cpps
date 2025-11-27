#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), name("default"){
	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap " << name << " constructed" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string diamondName) : ClapTrap(diamondName + "_clap_name"), FragTrap(), ScavTrap(), name(diamondName){
	std::cout << "DiamondTrap " << name << " constructed" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
}

void DiamondTrap::whoAmI(){
	std::cout << "My DiamondTrap name is " << name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) :
	ClapTrap(other.ClapTrap::name), FragTrap(), ScavTrap() {
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "DiamondTrap " << name << " copy constructed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other){
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	return *this;
}

void	DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << name << " destructed" << std::endl;
}