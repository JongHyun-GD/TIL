#include "Fixed.hpp"

Fixed::Fixed() {
	this->rawBits = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &newFixed) {
	this->rawBits = newFixed.getRawBits();
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed& Fixed::operator= (const Fixed &newFixed) {
	std::cout << "Assignation operator called\n";
	this->rawBits = newFixed.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return this->rawBits;
}

void Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
	std::cout << "setRawBits member function called\n";
}
