#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure")
{
	std::cout << "\033[1;32mCure is appeared.\033[0m\n";
}

Cure::Cure(Cure &other)
	: AMateria("cure")
{
	std::cout << "\033[1;32mCure is appeared.\033[0m\n";
}

Cure *Cure::clone() const
{
	Cure *newCure = new Cure();
	std::cout << "\033[1;32mCure is cloned.\033[0m\n";
	return newCure;
}

Cure::~Cure()
{
	std::cout << "\033[1;32mCure is disappeared.\033[0m\n";
}

void Cure::use(ICharacter &target)
{
	std::cout << "\033[1;32m* heals " << target.getName() << "'s wounds *\033[0m\n";
}
