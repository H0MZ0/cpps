#include "Zombie.hpp"

void    Zombie::announce( void ){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(){
    std::cout << "Default Constructor called" << std::endl;
}

Zombie::~Zombie (){
    std::cout << "Default Destructor called" << std::endl;
}