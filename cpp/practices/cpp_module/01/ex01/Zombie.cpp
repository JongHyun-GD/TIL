#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << "<" << name << "> BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie(void)
{
	std::cout << name << " is dead..\n";
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
