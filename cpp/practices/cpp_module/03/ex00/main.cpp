#include "ClapTrap.hpp"

int main() {
	ClapTrap jong("Jong");
	ClapTrap hyun("Hyun");

	jong.attack("hyun");
	jong.takeDamage(10);
	jong.beRepaired(10);

	return 0;
}
