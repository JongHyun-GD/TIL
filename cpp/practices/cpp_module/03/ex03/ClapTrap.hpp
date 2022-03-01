#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &orig);
	ClapTrap(std::string name, int energyPoints);
	ClapTrap &operator= (ClapTrap &orig);
	~ClapTrap();

	virtual void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName();


protected:
	std::string name;
	int hitpoints;
	int energyPoints;
	int attackDamage;
};

#endif
