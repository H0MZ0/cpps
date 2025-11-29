#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal{
	private:
	std::string sound;

	public:
	Dog();
	Dog(const Dog &other);
	Dog& operator=(const Dog &other);
	~Dog();
	std::string getType() const;
	void makeSound() const;


};