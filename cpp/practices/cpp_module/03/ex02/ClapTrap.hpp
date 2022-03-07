#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &orig);
	ClapTrap &operator= (ClapTrap &orig);
	~ClapTrap();

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
protected:
	ClapTrap();
	std::string name;
	int hitpoints;
	int energyPoints;
	int attackDamage;
};

#endif
