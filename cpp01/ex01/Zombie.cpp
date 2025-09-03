#include "Zombie.hpp"

void    Zombie::announce( void ){
    std::cout << "Name is "<< name << std::endl;
}

Zombie::Zombie(){
    std::cout << "Default Constructor called" << std::endl;
}

Zombie::~Zombie (){
    std::cout << "Default Destructor called" << std::endl;
}

void Zombie::setName( std::string n ){
    name = n;
}

std::string Zombie::getName(){
    return Zombie::name;
}

