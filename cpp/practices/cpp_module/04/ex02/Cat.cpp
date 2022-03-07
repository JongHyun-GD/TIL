#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	brain = new Brain();
	std::cout << "Cat is constructed.\n";
}

Cat::Cat(Cat &other)
{
	this->type = other.type;
	this->brain = new Brain(*(other.brain));
	std::cout << "Cat is constructed.\n";
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat is deconstructed.\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow~\n";
}

Cat &Cat::operator=(Cat &other)
{
	this->type = other.getType();
	*(this->brain) = *(other.brain);

	return *this;
}
