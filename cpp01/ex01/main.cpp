#include "Zombie.hpp"

int main(){
    Zombie z;
    Zombie* ptr = z.zombieHorde(3, "hamza");
    ptr[0].setName("Hamza");
    ptr[0].announce();
    ptr[1].setName("Said");
    ptr[1].announce();
    ptr[2].setName("Aymane");
    ptr[2].announce();
    // for (int i = 1; i <= 3; i++)
    //     std::cout << "Zombie["<< i << "] = " << ptr[i - 1].getName() << std::endl;
    delete[] ptr;
}