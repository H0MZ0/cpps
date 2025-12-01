#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class AMateria;

class Ice : public AMateria{
	public:
	Ice();
	Ice& operator=(const Ice &other);
	Ice(const Ice &other);
	~Ice();

	virtual AMateria* clone() const;
	void use(ICharacter& target);

};