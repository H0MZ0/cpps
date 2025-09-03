#include "Zombie.hpp"

void Zombie::randomChump( std::string name ){
    setName(name);
    announce();
}