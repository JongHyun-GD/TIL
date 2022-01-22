#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain is constructed.\n";
}

Brain::Brain(Brain &other)
{
	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain is constructed.\n";
}

Brain &Brain::operator=(Brain &other)
{
	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain is deconstructed.\n";
}
