#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "=== Creating ClapTrap ===" << std::endl;
    ClapTrap clap("CL4P-TP");
    std::cout << std::endl;

    std::cout << "=== Creating ScavTrap ===" << std::endl;
    ScavTrap scav("SC4V-TP");
    std::cout << std::endl;

    std::cout << "=== Creating FragTrap ===" << std::endl;
    FragTrap frag("FR4G-TP");
    std::cout << std::endl;

    std::cout << "=== Testing ClapTrap attack ===" << std::endl;
    clap.attack("target dummy");
    std::cout << std::endl;

    std::cout << "=== Testing ScavTrap attack ===" << std::endl;
    scav.attack("enemy bot");
    std::cout << std::endl;

    std::cout << "=== Testing FragTrap attack ===" << std::endl;
    frag.attack("hostile robot");
    std::cout << std::endl;

    std::cout << "=== Testing damage and repair ===" << std::endl;
    frag.takeDamage(30);
    frag.beRepaired(20);
    std::cout << std::endl;

    std::cout << "=== Testing ScavTrap special ability ===" << std::endl;
    scav.guardGate();
    std::cout << std::endl;

    std::cout << "=== Testing FragTrap special ability ===" << std::endl;
    frag.highFivesGuys();
    std::cout << std::endl;

    std::cout << "=== Destructors will be called ===" << std::endl;
    return 0;
}
