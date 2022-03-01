#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "Cat";
	std::cout << "Cat is constructed.\n";
}

WrongCat::WrongCat(WrongCat &other)
{
	this->type = other.type;
	std::cout << "Cat is constructed.\n";
}

WrongCat::~WrongCat()
{
	std::cout << "Cat is deconstructed.\n";
}

void WrongCat::makeSound() const
{
	std::cout << "Meow~\n";
}

WrongCat &WrongCat::operator=(WrongCat &other)
{
	this->type = other.getType();
	return *this;
}
