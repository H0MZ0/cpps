#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB{
	private:
		std::string	name;
		std::string	weapon;

	public:
		void	attack( void );
		void	setType( std::string n );
		void	setWeapon( class Weapon );
};

#endif
