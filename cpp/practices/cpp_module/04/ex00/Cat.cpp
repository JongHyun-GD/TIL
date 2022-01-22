#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat is constructed.\n";
}

Cat::Cat(Cat &other)
{
	this->type = other.type;
	std::cout << "Cat is constructed.\n";
}

Cat::~Cat()
{
	std::cout << "Cat is deconstructed.\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow~\n";
}

Cat &Cat::operator=(Cat &other)
{
	this->type = other.getType();
	return *this;
}
