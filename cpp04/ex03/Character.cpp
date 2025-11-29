#include "Character.hpp"

Character::Character() : name("default"){
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		amateria[i] = NULL;
}

Character::Character(std::string name) : name(name){
	std::cout << "Character " << name << " constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		amateria[i] = NULL;
}

Character& Character::operator=(const Character &other){
	std::cout << "Character " << name << " copy operator called" << std::endl;
	if (this != &other){
		name = other.name;
		for (int i = 0; i < 4; i++){
			amateria[i] = other.amateria[i];
		}
	}
	return *this;
}

Character::Character(const Character &other){
	std::cout << "Character " << name << " copy constructor called" << std::endl;
	name = other.name;
	for(int i = 0; i < 4; i++){
		if (other.amateria[i])
			amateria[i] = other.amateria[i]->clone();
	}
}

Character::~Character(){
	std::cout << "Character default destructor called" << std::endl;
	for (int i = 0; i < 4; i++){
		if(amateria[i])
			delete amateria[i];
	}
	delete amateria;
}


std::string const & Character::getName(){
	return name;
}

void Character::equip(AMateria* m){
	if (!m)
		return;
	for (int i = 0;i < 4; i++){
		if(!amateria[i]){
			amateria[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx){
	if (idx < 0 && idx > 3)
		return;
	for (int i = 0;i < 4; i++){
		if(amateria[i])
			amateria[i] = NULL;
	}
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 && idx > 3)
		return;
	if (amateria[idx])
		amateria[idx]->use(target);
}
