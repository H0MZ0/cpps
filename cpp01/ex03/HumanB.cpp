#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string n) : name(n), weapon(NULL) {}

void HumanB::setWeapon(Weapon& w) {
    weapon = &w;
}

void HumanB::attack(void) {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon" << std::endl;
}
