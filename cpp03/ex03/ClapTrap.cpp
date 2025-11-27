#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("defaut"), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : name(Name), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "ClapTrap " << name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other){
	std::cout << "ClapTrap copy constructor called" << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other){
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other){
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target){
	if (hitPoints <= 0 || energyPoints <= 0){
		std::cout << "ClapTrap " << name << " has no energy points left to attack!" << std::endl;
	}
	else {
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks "
				  << target << " , causing " << attackDamage
				  << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	hitPoints -= amount;
	if (hitPoints < 0){
		std::cout << "ClapTrap " << name << " is dead!" << std::endl;
		hitPoints = 0;
		return;
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount){
	if (hitPoints <= 0 || energyPoints <= 0)
		std::cout << "ClapTrap " << name << " has no energy points left to attack!" << std::endl;
	else {
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name << " is repaired by " << amount << " points!" << std::endl;
	}
}
ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << name << " destructed!" << std::endl;
}