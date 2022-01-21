#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap construction func called\n";
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	int temp_hp;
	int temp_ep;
	this->_name = name;
	this->hitpoints = this->FragTrap::hitpoints;
	//this->energyPoints = this->ScavTrap::energyPoints;
	this->attackDamage = this->FragTrap::attackDamage;
	std::cout << "DiamondTrap construction func called\n";
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "DiamondTrap hitPoints: " << this->hitpoints << std::endl;
	std::cout << "DiamondTrap energyPoints: " << this->energyPoints << std::endl;
	std::cout << "DiamondTrap attackDamage: " << this->attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &other)
	: ClapTrap(other.getName()) {
	this->_name = other._name;
	this->hitpoints = other.hitpoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "DiamondTrap construction func called\n";
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "DiamondTrap hitPoints: " << this->hitpoints << std::endl;
	std::cout << "DiamondTrap energyPoints: " << this->energyPoints << std::endl;
	std::cout << "DiamondTrap attackDamage: " << this->attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap deconstruction func called\n";
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << this->_name << ", and my claptrap's name is " << this->getName() << ".\n";
}
