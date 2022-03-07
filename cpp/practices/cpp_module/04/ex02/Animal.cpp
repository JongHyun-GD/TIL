#include "Animal.hpp"

Animal::Animal()
{
	this->type = "";
	std::cout << "Animal is constructed.\n";
}

Animal::Animal(Animal &other)
{
	this->type = other.getType();
	std::cout << "Animal is constructed.\n";
}

Animal::~Animal()
{
	std::cout << "Animal is deconstructed.\n";
}

std::string Animal::getType() const
{
	return this->type;
}

Animal &Animal::operator=(Animal &other)
{
	this->type = other.getType();
	return *this;
}
