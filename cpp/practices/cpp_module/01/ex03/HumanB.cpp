#include "HumanB.hpp"

HumanB::HumanB(const std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::attack()
{
	if (this->weapon)
		std::cout << this->name << " attacks with his " << this->weapon->getType() << "\n";
}

void HumanB::setWeapon(Weapon& newWeapon)
{
	this->weapon = &newWeapon;
}
