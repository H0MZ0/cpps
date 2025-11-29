#pragma once

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria{
	private:


	public:
	Cure();
	Cure& operator=(const Cure &other);
	Cure(const Cure &other);
	~Cure();

	virtual AMateria* clone() const;
	void use(ICharacter& target);
};