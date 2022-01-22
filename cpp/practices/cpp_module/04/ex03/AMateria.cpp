#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	_type = type;
}

AMateria::~AMateria()
{
	std::cout << "AMateria is disappeared.\n";
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Materia " << _type << " is casted to " << target.getName() << "\n";
}
