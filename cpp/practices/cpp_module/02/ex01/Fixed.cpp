#include "Fixed.hpp"

void Fixed::print_float_bit(float f) {
	int *p = (int *)&f;
	int bit[32];
	for (int i=0;i<32;++i) {
		bit[i] = (*p) & 1;
		(*p) = (*p) >> 1;
	}
	int cnt =0;
	for (int i=31;i>=0;--i) {
		cnt++;
		std::cout << bit[i];
		if (cnt % 8 == 0) std::cout << " ";
	}
	std::cout << std::endl;
}

Fixed::Fixed() {
	this->rawBits = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &newFixed) {
	this->rawBits = newFixed.getRawBits();
	std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const int value) {
	int mask = (1 << 23) - 1; // mask to get 0~22 bits
	int sign_mask = (1 << 31); // mask to get sign
	std::cout << (value & mask) << std::endl;
	this->rawBits = (value & mask) << frac;
	this->rawBits = (value & sign_mask) | rawBits;

	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value) {
	int *p = (int *)&value;
	int exponent = 0;
	int mantissa = 0;
	this->rawBits = 0;
	int exp_mask = ((1 << 8) - 1) << 23;
	int mant_mask = ((1 << 23) - 1);
	std::cout << value << std::endl;
	print_float_bit(value);
	exponent = ((exp_mask & (*p)) >> 23) - 127;
	std::cout << "exp:\t" << exponent << std::endl;
	mantissa = (mant_mask & (*p));
	std::cout << "int:\t" << (mantissa >> (23 - exponent)) << std::endl;

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
	float res = 0;
	int *p = (int*)&res;


	return res;
}

int Fixed::toInt(void) const {
	int mask = ((1 << 23) - 1) << frac;
	int sign_mask = ((1 << 31));
	int res = (mask & this->rawBits) >> frac;
	res |= sign_mask & this->rawBits;
	return res;
}
