#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
public:
	ScavTrap(std::string name);
	ScavTrap(ScavTrap &other);
	~ScavTrap();
	void guardGate();

	ScavTrap &operator=(ScavTrap &other);
protected:
	ScavTrap();
};

#endif
