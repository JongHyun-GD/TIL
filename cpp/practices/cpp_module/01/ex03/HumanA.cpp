#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon& weapon)
	: weapon(weapon)
{
	this->name = name;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with his " << this->weapon.getType() << "\n";
}

void HumanA::setWeapon(const Weapon& newWeapon)
{
	this->weapon = newWeapon;
}
