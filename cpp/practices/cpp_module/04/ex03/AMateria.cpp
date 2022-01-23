#include "AMateria.hpp"

AMateria::AMateria()
{
	_type = "";
}

AMateria::AMateria(std::string const &type)
{
	_type = type;
}

AMateria::~AMateria()
{
	std::cout << "AMateria is disappeared.\n";
}

AMateria &AMateria::operator= (AMateria &other)
{
	_type = other._type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Materia " << _type << " is casted to " << target.getName() << "\n";
}
