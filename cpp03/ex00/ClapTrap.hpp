#pragma once

#include <iostream>

class ClapTrap
{
	private:
	std::string name;
	int	hitPoints;
	int	energyPoints;
	int	attackDamage;
	ClapTrap();
	
	public:
	ClapTrap(std::string Name);
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator=(const ClapTrap &other);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
