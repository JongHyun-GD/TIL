#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->name = "";
	std::cout << "FragTrap construction func called\n";
}

FragTrap::FragTrap(std::string name) {
	this->name = name;
	this->hitpoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap construction func called\n";
}

FragTrap::FragTrap(FragTrap &other) {
	this->name = other.name;
	this->hitpoints = other.hitpoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "FragTrap construction func called\n";
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destruction func called.\n";
}

FragTrap &FragTrap::operator=(FragTrap &other) {
	this->name = other.name;
	this->hitpoints = other.hitpoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "FragTrap assignation operator func called\n";
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->name << " requests positive high five.\n";
}
