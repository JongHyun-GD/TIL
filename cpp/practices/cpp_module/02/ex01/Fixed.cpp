#include "Fixed.hpp"

Fixed::Fixed() {
	this->rawBits = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &newFixed) {
	this->rawBits = newFixed.getRawBits();
	std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const int value) {
	this->rawBits = (value & (1 << 31)) | (value << this->frac);
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value) {
	this->rawBits = roundf(value * (1 << frac));
	std::cout << "Float constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed& Fixed::operator= (const Fixed &newFixed) {
	std::cout << "Assignation operator called\n";
	this->rawBits = newFixed.getRawBits();
	return *this;
}

std::ostream& operator<< (std::ostream& os, const Fixed &f) {
	os << f.toFloat();
	return os;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return this->rawBits;
}

void Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
	std::cout << "setRawBits member function called\n";
}

float Fixed::toFloat(void) const {
	return ((float)this->rawBits / (float)(1 << frac));
}

int Fixed::toInt(void) const {
	return (this->rawBits / (1 << frac));
}
