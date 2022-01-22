#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static const int MAX_MATERIA = 4;
	int learnedMateriaSize;
	AMateria *learnedMateria[MAX_MATERIA];

public:
	MateriaSource();
	MateriaSource(MateriaSource &other);
	MateriaSource &operator=(MateriaSource &other);
	~MateriaSource();

	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};

#endif
