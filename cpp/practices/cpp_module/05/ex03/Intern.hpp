#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern &other);
	Intern& operator=(Intern &other);
	virtual ~Intern();

	Form*	makeForm(std::string form, std::string target);

	class UnknownFormException : public std::exception {
		virtual const char* what() const throw();
	};
};

#endif
