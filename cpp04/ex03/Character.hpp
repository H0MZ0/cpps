#pragma once

#include <iostream>
#include <AMateria.hpp>


class Character{
	private:
	std::string name;
	AMateria* amateria[4];

	public:
	Character();
	Character(std::string name);
	Character& operator=(const Character &other);
	Character(const Character &other);
	~Character();


	std::string const & getName();
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};