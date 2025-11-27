#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "Default ScavTrap constructor called!" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	name = "default";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap " << name << " copy constructed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name){
	std::cout << "ScavTrap " << name << " constructed" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (energyPoints <= 0 || hitPoints <= 0) {
		std::cout << "ScavTrap " << name << " has no energy or hit points left to attack." << std::endl;
	}
	else {
		energyPoints--;
		std::cout << "ScavTrap " << name << " attacks "
				  << target << ", causing " << attackDamage
				  << " points of damage!" << std::endl;
	}
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " destructed" << std::endl;
}