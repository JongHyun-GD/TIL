#ifndef CASTER_HPP
#define CASTER_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <errno.h>

class Caster
{
private:
	Caster();

	char* _data;
public:
	Caster(char* data);
	Caster(Caster &other);
	Caster &operator=(Caster &other);
	virtual ~Caster();

	char* getData() const;

	operator char() const;
	operator int() const;
	operator float() const;
	operator double() const;
};

#endif
