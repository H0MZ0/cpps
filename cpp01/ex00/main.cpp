#include "Zombie.hpp"

int main(){
    Zombie z;
    Zombie *ptr;
    z.randomChump("Stack");
    ptr = z.newZombie("Heap");
    delete ptr;
	return 0;
}