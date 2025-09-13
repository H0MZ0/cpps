#include "Zombie.hpp"

int main() {
    int N = 0;
	if (N < 0)
		return 1;
    Zombie* horde = zombieHorde(N, "Hamza");

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}
