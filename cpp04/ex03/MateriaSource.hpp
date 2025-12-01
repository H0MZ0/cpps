#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource{
	private:
	AMateria* amateria[4];

	public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource& operator=(const MateriaSource &other);
	~MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

};