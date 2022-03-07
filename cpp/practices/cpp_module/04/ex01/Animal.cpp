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

void Animal::makeSound() const
{
	std::cout << "Hey, how can I make a noise?\n";
}

Animal &Animal::operator=(Animal &other)
{
	this->type = other.getType();
	return *this;
}
