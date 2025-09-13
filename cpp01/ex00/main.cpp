#include "Zombie.hpp"

int main() {
    randomChump("StackZombie");

    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    return 0;
}
