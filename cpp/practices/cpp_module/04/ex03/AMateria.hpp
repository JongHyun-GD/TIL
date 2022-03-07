#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
private:
	AMateria();
	AMateria &operator= (AMateria &other);
protected:
	std::string _type;
public:
	AMateria(std::string const &type);
	virtual ~AMateria();
	std::string const &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
