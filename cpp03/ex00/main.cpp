#include "ClapTrap.hpp"

int main() {
	ClapTrap clap("CL4P-TP");

	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(3);

	return 0;
}