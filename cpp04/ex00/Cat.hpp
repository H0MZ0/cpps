#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal{
	private:
	std::string sound;

	public:
	Cat();
	Cat(const Cat &other);
	Cat& operator=(const Cat &other);
	~Cat();
	std::string getType() const;
	void makeSound() const;


};