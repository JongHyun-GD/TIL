#include "ScavTrap.hpp"

int main() {
	ScavTrap scav1("Scav1");

	scav1.attack("Clap1");
	scav1.takeDamage(10);
	scav1.beRepaired(10);
	scav1.guardGate();

	return 0;
}
