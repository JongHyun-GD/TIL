#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
	:_name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &other)
	:_name(other.getName()), _grade(other.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &other)
{
	_grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "[ERROR] Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "[ERROR] Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
