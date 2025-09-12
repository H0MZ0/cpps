#include "Harl.hpp"

void Harl::debug( void ){
	std::cout << "\"DEBUG\" level: " << "Hey BRO make it correctly" << std::endl;
}

void Harl::info( void ){
	std::cout << "\"INFO\" level: " << "Nice you are in it !" << std::endl;
}

void Harl::warning( void ){
	std::cout << "\"WARNING\" level: " << "Are you stupid" << std::endl;

}

void Harl::error( void ){
	std::cout << "\"ERROR\" level: " << "Dont't be like SAID" << std::endl;
}

void Harl::complain( std::string level ){
	std::string help[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++){
		if (level == help[i]){
			(this->*ptr[i])();
			return;
		}
	}
	std::cout << "[ Invalid Case ]\n";
}
