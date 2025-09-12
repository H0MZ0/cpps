#include "Zombie.hpp"

void Zombie::randomChump( std::string name ){
    Zombie *ptr = new Zombie();
    ptr->setName(name);
    ptr->announce();
    delete ptr;
}