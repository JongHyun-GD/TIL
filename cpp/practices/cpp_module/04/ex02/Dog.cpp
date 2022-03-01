#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	brain = new Brain();
	std::cout << "Dog is constructed.\n";
}

Dog::Dog(Dog &other)
{
	this->type = other.type;
	this->brain = new Brain(*(other.brain));
	std::cout << "Dog is constructed.\n";
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog is deconstructed.\n";
}

void Dog::makeSound() const
{
	std::cout << "Mung!\n";
}

Dog &Dog::operator=(Dog &other)
{
	this->type = other.getType();
	*(this->brain) = *(other.brain);

	return *this;
}
