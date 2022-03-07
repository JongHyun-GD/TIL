#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
	using ScavTrap::energyPoints;
	using ScavTrap::attack;
	using ClapTrap::getName;

	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap &other);
	~DiamondTrap();
	void whoAmI();

	DiamondTrap &operator=(DiamondTrap &other);
protected:
	DiamondTrap();
private:
	std::string _name;
};

#endif
