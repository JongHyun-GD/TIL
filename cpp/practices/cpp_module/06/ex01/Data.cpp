#include "Data.hpp"

Data::Data(std::string &name, int grade, float damage, double weight)
	:_name(name), _grade(grade), _damage(damage), _weight(weight) {}

Data::Data(Data &other)
	:_name(other.getName()), _grade(other.getGrade()), \
	_damage(other.getDamage()), _weight(other.getWeight()) {}

Data& Data::operator=(Data &other)
{
	_name = other.getName();
	_grade = other.getGrade();
	_damage = other.getDamage();
	_weight = other.getWeight();
	return *this;
}

Data::~Data() {}

const std::string& Data::getName() const { return _name; }

int Data::getGrade() const { return _grade; }

float Data::getDamage() const { return _damage; }

double Data::getWeight() const { return _weight; }

std::ostream& operator<< (std::ostream& out, Data *data)
{
	out << "<==== Data ====>\n";
	out << "Name: " << data->getName() << "\n";
	out << "Grade: " << data->getGrade() << "\n";
	out << "Damage: " << data->getDamage() << "\n";
	out << "Weight: " << data->getWeight() << "\n";
	return out;
}

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t ptr)
{
	return reinterpret_cast<Data*>(ptr);
}


