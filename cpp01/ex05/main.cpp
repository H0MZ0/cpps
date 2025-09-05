#include "Harl.hpp"

int main(int ac, char **av){
	if (ac != 2)
		return 1;
	Harl a;
	a.complain(av[1]);
	// a.complain("DEBUG");
	// a.complain("INFO");
	// a.complain("WARNING");
	// a.complain("ERROR");
	// a.complain("hola");
}