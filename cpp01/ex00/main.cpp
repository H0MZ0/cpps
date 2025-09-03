#include "Zombie.hpp"

int main(){
    Zombie z;
    Zombie *ptr;
    z.randomChump("STACK");
    ptr = z.newZombie("Heap");
    delete ptr;
}