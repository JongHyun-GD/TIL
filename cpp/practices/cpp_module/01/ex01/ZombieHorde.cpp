#include "Zombie.hpp"

Zombie *ZombieHorde(int N, std::string name)
{
	Zombie *horde;
	horde = new Zombie[N];

	for (int i = 0; i < N; ++i)
	{
		std::stringstream sstream;
		sstream << i;
		std::string temp_name = name + sstream.str();
		horde[i].setName(temp_name);
	}

	return horde;
}
