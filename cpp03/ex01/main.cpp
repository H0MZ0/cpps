#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");

    std::cout << std::endl;

    clap.attack("target dummy");
    scav.attack("enemy bot");

    std::cout << std::endl;

    scav.takeDamage(30);
    scav.beRepaired(20);

    std::cout << std::endl;

    scav.guardGate();

    std::cout << std::endl;

    return 0;
}
