#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data
{
private:
	Data();

	std::string	_name;
	int			_grade;
	float		_damage;
	double		_weight;
public:
	Data(std::string &name, int _grade, float _damage, double _weight);
	Data(Data &other);
	Data &operator= (Data &other);
	virtual ~Data();

	const std::string &getName() const;
	int getGrade() const;
	float getDamage() const;
	double getWeight() const;
};

std::ostream& operator<<(std::ostream& out, Data *data);

uintptr_t serialize(Data*);
Data* deserialize(uintptr_t);

#endif
