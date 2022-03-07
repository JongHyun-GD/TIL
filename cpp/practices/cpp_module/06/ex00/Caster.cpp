#include "Caster.hpp"

Caster::Caster() {}

Caster::Caster(char* str)
	:_data(str) {}

Caster::Caster(Caster &other) {(void)other;}

Caster& Caster::operator=(Caster &other) {this->_data = other.getData(); return *this;}

Caster::~Caster() {}

char *Caster::getData() const
{
	return this->_data;
}

Caster::operator char() const
{
	double res = 0;
	char *endptr;
	res = strtod(this->_data, &endptr);
	if (std::isnan(res) || std::isinf(res)) // overflow
		std::cout << "char: impossible" << std::endl;
	else if (res == 0.0 && *endptr != '\0')
		std::cout << "char: impossible" << std::endl;
	else if ((int)res >= ' ' && (int)res <= '~')
		std::cout << "char: " << (char)((int)res) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	return (char)((int)res);
}

Caster::operator int() const
{
	double res = 0;
	char *endptr;
	res = strtod(this->_data, &endptr);
	if (std::isnan(res) || std::isinf(res)) // overflow
		std::cout << "int: impossible" << std::endl;
	else if (res == 0.0 && *endptr != '\0')
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << (int)res << std::endl;
	return (int)res;
}

Caster::operator float() const
{
	double res = 0;
	char *endptr;
	res = strtod(this->_data, &endptr);
	if (res == 0.0 && *endptr != '\0')
		std::cout << "float: impossible" << std::endl;
	else
	{
		if (std::isinf(res))
			std::cout << std::showpos;
		std::cout << "float: " << (float)res << "f" << std::endl;
		if (std::isinf(res))
			std::cout << std::noshowpos;
	}
	return (float)res;
}

Caster::operator double() const
{
	double res = 0;
	char *endptr;
	res = strtod(this->_data, &endptr);
	if (res == 0.0 && *endptr != '\0')
		std::cout << "double: impossible" << std::endl;
	else
	{
		if (std::isinf(res))
			std::cout << std::showpos;
		std::cout << "double: " << res << std::endl;
		if (std::isinf(res))
			std::cout << std::noshowpos;
	}
	return res;
}
