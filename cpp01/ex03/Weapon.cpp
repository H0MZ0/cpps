#include "Weapon.hpp"

std::string const& Weapon::getType(){
    return type;
}

void Weapon::setType(std::string n){
    type = n;
}