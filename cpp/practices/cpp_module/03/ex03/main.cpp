#include "DiamondTrap.hpp"

int main() {
	DiamondTrap dTrap("Dia1");

	dTrap.attack("Dummy");
	dTrap.guardGate();
	dTrap.highFivesGuys();
	dTrap.whoAmI();

	DiamondTrap dTrap2(dTrap);
	dTrap2.attack("Dummy2");
	dTrap2.guardGate();
	dTrap2.highFivesGuys();
	dTrap2.whoAmI();

	return 0;
}
