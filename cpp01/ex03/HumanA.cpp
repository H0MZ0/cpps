#include "HumanA.hpp"

HumanA::HumanA(std::string w, Weapon& weapon) : name(w), weapon(weapon) {}

void	HumanA::attack( void ){
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
