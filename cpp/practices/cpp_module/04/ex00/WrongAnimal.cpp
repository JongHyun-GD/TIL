#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "";
	std::cout << "Animal is constructed.\n";
}

WrongAnimal::WrongAnimal(WrongAnimal &other)
{
	this->type = other.getType();
	std::cout << "Animal is constructed.\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Animal is deconstructed.\n";
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Hey, how can I make a noise?\n";
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &other)
{
	this->type = other.getType();
	return *this;
}
