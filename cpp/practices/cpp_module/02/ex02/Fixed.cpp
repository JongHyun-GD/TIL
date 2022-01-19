#include "Fixed.hpp"

Fixed::Fixed()
{
	this->rawBits = 0;
	//std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &newFixed)
{
	this->rawBits = newFixed.getRawBits();
	//std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const int value)
{
	this->rawBits = (value & (1 << 31)) | (value << this->frac);
	//std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value)
{
	this->rawBits = roundf(value * (1 << frac));
	//std::cout << "Float constructor called\n";
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called\n";
}

bool Fixed::operator<(Fixed const &other) const
{
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator<=(Fixed const &other) const
{
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator>(Fixed const &other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator>=(Fixed const &other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator==(Fixed const &other) const
{
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(Fixed const &other) const
{
	return this->getRawBits() != other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &newFixed)
{
	std::cout << "Assignation operator called\n";
	this->rawBits = newFixed.getRawBits();
	return *this;
}

Fixed Fixed::operator+(Fixed const &other)
{
	Fixed val(this->toFloat() + other.toFloat());

	return val;
}

Fixed Fixed::operator-(Fixed const &other)
{
	Fixed val(this->toFloat() - other.toFloat());

	return val;
}

Fixed Fixed::operator*(Fixed const &other)
{
	Fixed val(this->toFloat() * other.toFloat());

	return val;
}

Fixed Fixed::operator/(Fixed const &other)
{
	Fixed val(this->toFloat() / other.toFloat());

	return val;
}

Fixed Fixed::operator++()
{
	this->rawBits++;

	return (*this);
}

Fixed Fixed::operator++ (int)
{
	Fixed temp(this->toFloat());
	this->rawBits++;

	return (temp);
}

Fixed Fixed::operator-- ()
{
	this->rawBits--;

	return (*this);
}

Fixed Fixed::operator-- (int)
{
	Fixed temp(this->toFloat());
	this->rawBits--;

	return (temp);
}

std::ostream &operator<<(std::ostream &os, Fixed const &f)
{
	os << f.toFloat();
	return os;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return this->rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
	std::cout << "setRawBits member function called\n";
}

float Fixed::toFloat(void) const
{
	return ((float)this->rawBits / (float)(1 << frac));
}

int Fixed::toInt(void) const
{
	return (this->rawBits / (1 << frac));
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return a;
	else
		return b;
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return a;
	else
		return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return a;
	else
		return b;
}
