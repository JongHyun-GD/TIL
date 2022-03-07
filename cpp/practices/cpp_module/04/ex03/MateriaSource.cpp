#include "MateriaSource.hpp"
MateriaSource::MateriaSource()
	: learnedMateriaSize(0)
{
	std::cout << "Materia Source is created.\n";
}

MateriaSource::MateriaSource(MateriaSource &other)
	: learnedMateriaSize(other.learnedMateriaSize)
{
	for (int i=0; i<learnedMateriaSize; ++i)
	{
		learnedMateria[i] = other.learnedMateria[i]->clone();
	}
	std::cout << "Materia Source is created.\n";
}

MateriaSource &MateriaSource::operator=(MateriaSource &other)
{
	learnedMateriaSize = other.learnedMateriaSize;
	for (int i=0; i<learnedMateriaSize; ++i)
	{
		learnedMateria[i] = other.learnedMateria[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i=0; i<learnedMateriaSize; ++i)
		delete learnedMateria[i];
	std::cout << "Materia Source is disappeared.\n";
}

void MateriaSource::learnMateria(AMateria *materia)
{
	learnedMateria[learnedMateriaSize++] = materia;
	std::cout << "Materia source learned " << materia->getType() << ".\n";
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i=0; i<learnedMateriaSize; ++i)
	{
		if (learnedMateria[i]->getType() == type)
		{
			return learnedMateria[i]->clone();
		}
	}

	std::cout << "Materia source doesn't have " << type << " materia.\n";
	return NULL;
}
