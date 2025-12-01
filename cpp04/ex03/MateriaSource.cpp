#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		amateria[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other){
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for(int i = 0; i < 4; i++){
		this->amateria[i] = NULL;
	}
	for(int i = 0; i < 4; i++){
		if (other.amateria[i] != NULL)
			this->amateria[i] = other.amateria[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other){
	std::cout << "MateriaSource copy operator called" << std::endl;
	if (this != &other){
		for (int i = 0; i < 4; i++){
			if (this->amateria[i] != NULL){
				delete this->amateria[i];
				this->amateria[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++){
			if (other.amateria[i] != NULL)
				this->amateria[i] = other.amateria[i]->clone();
			else
				this->amateria[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource default destructor called" << std::endl;
	for (int i = 0; i < 4; i++){
		if(amateria[i])
			delete amateria[i];
	}
}


void MateriaSource::learnMateria(AMateria *m){
	if (!m)
		return;
	for (int i = 0; i < 4; i++){
		if (!amateria[i]){
			amateria[i] = m;
			return;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++){
		if (amateria[i] && amateria[i]->getType() == type)
				return (amateria[i]->clone());
	}
	return NULL;
}

