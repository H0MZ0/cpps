#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
	std::string sound;
	Brain* brain;

	public:
	Cat();
	Cat(const Cat &other);
	Cat& operator=(const Cat &other);
	~Cat();
	std::string getType() const;
	void makeSound() const;


};