#include "Zombie.hpp"

Zombie::Zombie(std::string n) : name(n) {}

Zombie::~Zombie() {
    std::cout << "Zombie " << name << " is destroyed" << std::endl;
}

void Zombie::announce(void) const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
