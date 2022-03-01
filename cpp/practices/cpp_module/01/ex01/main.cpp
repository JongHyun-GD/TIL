#include "Zombie.hpp"

int main(void)
{
	int N = 20;
	Zombie* horde = ZombieHorde(N, "zombie");
	for (int i = 0; i < N; ++i)
	{
		horde[i].announce();
	}

	delete[] horde;
}
