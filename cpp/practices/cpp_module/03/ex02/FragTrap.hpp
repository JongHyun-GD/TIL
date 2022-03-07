#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap &other);
	~FragTrap();
	void highFivesGuys();

	FragTrap &operator=(FragTrap &other);
};

#endif
