#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
	std::string sound;
	Brain* brain;

	public:
	Dog();
	Dog(const Dog &other);
	Dog& operator=(const Dog &other);
	~Dog();
	std::string getType() const;
	void makeSound() const;


};