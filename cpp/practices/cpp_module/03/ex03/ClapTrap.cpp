#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	this->name = "";
	std::cout << "ClapTrap construction func called\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destruction func called.\n";
}

ClapTrap::ClapTrap(std::string name) {
	this->name = name;
	this->hitpoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap construction func called\n";
}

ClapTrap::ClapTrap(std::string name, int energyPoints) {
	this->name = name;
	this->hitpoints = 10;
	this->energyPoints = energyPoints;
	this->attackDamage = 0;
	std::cout << "ClapTrap construction func called\n";
}

ClapTrap::ClapTrap(ClapTrap &orig) {
	this->name = orig.name;
	this->hitpoints = orig.hitpoints;
	this->energyPoints = orig.energyPoints;
	this->attackDamage = orig.attackDamage;
	std::cout << "ClapTrzap copy construction func called\n";
}

ClapTrap &ClapTrap::operator=(ClapTrap &orig) {
	this->name = orig.name;
	this->hitpoints = orig.hitpoints;
	this->energyPoints = orig.energyPoints;
	this->attackDamage = orig.attackDamage;
	std::cout << "ClapTrap operator= func called\n";
	return *this;
}

void ClapTrap::attack(std::string const &target) {
	if (this->hitpoints > 0)
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\n";
	else
		std::cout << "ClapTrap " << this->name << " can not attack!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->hitpoints -= amount;
	if (this->hitpoints < 0) this->hitpoints = 0;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
	this->hitpoints += amount;
	std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points!\n";
}

std::string ClapTrap::getName() {
	return name;
}
