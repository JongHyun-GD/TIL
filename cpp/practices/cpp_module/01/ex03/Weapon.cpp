#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string& Weapon::getType()
{
	return this->type;
}


void Weapon::setType(const std::string &newType)
{
	this->type = newType;
}
