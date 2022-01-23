#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice")
{
	std::cout << "\033[1;36mIce is appeared.\033[0m\n";
}

Ice::Ice(Ice &other)
	: AMateria("ice")
{
	_type = other._type;
	std::cout << "\033[1;36mIce is appeared.\033[0m\n";
}

Ice *Ice::clone() const
{
	Ice *newIce = new Ice();
	std::cout << "\033[1;36mIce is cloned.\033[0m\n";
	return newIce;
}

Ice::~Ice()
{
	std::cout << "\033[1;36mIce is disappeared.\033[0m\n";
}

void Ice::use(ICharacter &target)
{
	std::cout << "\033[1;36m* shoots an ice bolt at " << target.getName() << " *\033[0m\n";
}
