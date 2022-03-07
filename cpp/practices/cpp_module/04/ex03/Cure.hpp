#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure &other);
	~Cure();
	Cure &operator=(Cure &other);

	Cure *clone() const;
	void use(ICharacter &target);
};

#endif
