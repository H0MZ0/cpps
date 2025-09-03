#include "Zombie.hpp"

void Zombie::setName( std::string n ){
    name = n;
}

Zombie* Zombie::newZombie( std::string name ){
    Zombie *ptr = new Zombie();
    ptr->setName(name);
    ptr->announce();
    return ptr;
}