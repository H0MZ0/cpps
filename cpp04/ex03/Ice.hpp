#pragma once

#include <AMateria.hpp>
#include <iostream>

class Ice : public AMateria{
	private:
	AMateria *Amateria;

	public:
	Ice();
	Ice& operator=(const Ice &other);
	Ice(const Ice &other);
	~Ice();

	virtual AMateria* clone() const;
	void use(ICharacter& target);

};