#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		std::string	weapon;

	public:
		HumanA(std::string w);
		void	attack( void );
		void	setType( std::string n );
		void	setWeapon( class Weapon );
};



#endif