#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ScavTrap scav1("Scav1");

	scav1.attack("Clap1");
	scav1.takeDamage(10);
	scav1.beRepaired(10);
	scav1.guardGate();

	FragTrap frag1("Frag1");

	frag1.attack("Clap1");
	frag1.takeDamage(20);
	frag1.beRepaired(20);
	frag1.highFivesGuys();

	return 0;
}
