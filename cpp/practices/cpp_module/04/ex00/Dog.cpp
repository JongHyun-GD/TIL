#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog is constructed.\n";
}

Dog::Dog(Dog &other)
{
	this->type = other.type;
	std::cout << "Dog is constructed.\n";
}

Dog::~Dog()
{
	std::cout << "Dog is deconstructed.\n";
}

void Dog::makeSound() const
{
	std::cout << "Mung!\n";
}

Dog &Dog::operator=(Dog &other)
{
	this->type = other.getType();
	return *this;
}
