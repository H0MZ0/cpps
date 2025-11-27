#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

    std::cout << "=== Creating DiamondTrap ===" << std::endl;
    DiamondTrap diamond("DI4M-TP");
    std::cout << std::endl;

    std::cout << "=== Testing DiamondTrap whoAmI ===" << std::endl;
    diamond.whoAmI();
    std::cout << std::endl;

    std::cout << "=== Testing DiamondTrap attack (should use ScavTrap's attack) ===" << std::endl;
    diamond.attack("ultimate target");
    std::cout << std::endl;

    std::cout << "=== Testing DiamondTrap special abilities ===" << std::endl;
    diamond.guardGate();
    diamond.highFivesGuys();
    std::cout << std::endl;

    std::cout << "=== Testing damage and repair ===" << std::endl;
    diamond.takeDamage(50);
    diamond.beRepaired(30);
    std::cout << std::endl;

    std::cout << "=== Testing copy constructor ===" << std::endl;
    DiamondTrap diamond2(diamond);
    diamond2.whoAmI();
    std::cout << std::endl;

    std::cout << "=== Destructors will be called (watch the order!) ===" << std::endl;
    return 0;
}
