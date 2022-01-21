#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->name = "";
	std::cout << "ScavTrap construction func called\n";
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hitpoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap construction func called\n";
}

ScavTrap::ScavTrap(ScavTrap &other) {
	this->name = other.name;
	this->hitpoints = other.hitpoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "ScavTrap construction func called\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destruction func called.\n";
}

ScavTrap &ScavTrap::operator=(ScavTrap &other) {
	this->name = other.name;
	this->hitpoints = other.hitpoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "ScavTrap assignation operator func called\n";

	return *this;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " has enterred in Gate keeper mode.\n";
}
