#pragma once

#include <iostream>
#include "AMateria.hpp"


class MateriaSource{
	private:
	AMateria* amateria[4];
	int count;

	public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource& operator=(const MateriaSource &other);
	~MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

};