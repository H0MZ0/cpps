#include "Harl.hpp"

void Harl::debug( void ){
	std::cout << "[ DEBUG ]\n" << "Hey BRO make it correctly" << std::endl;
}

void Harl::info( void ){
	std::cout << "[ INFO ]\n" << "Nice you are in it !" << std::endl;
}

void Harl::warning( void ){
	std::cout << "[ WARNING ]\n" << "Are you stupid" << std::endl;

}

void Harl::error( void ){
	std::cout << "[ ERROR ]\n" << "Dont't be like SAID" << std::endl;
}

void Harl::complain( std::string level ){
	std::string help[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	for (; help[i] != level && i < 4 ; i++){}
	switch (i)
	{
		case 0: debug(); // fall through
		case 1: info(); // fall through
		case 2: warning(); // fall through
		case 3: error(); break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
