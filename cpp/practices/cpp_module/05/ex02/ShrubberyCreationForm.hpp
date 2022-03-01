#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <fstream>
#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	std::string _target;

	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string &target);
	ShrubberyCreationForm(ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);

	const std::string& getTarget() const;

	class OpenFileException : public std::exception {
		virtual const char* what() const throw();
	};

	void execute(Bureaucrat &bureaucrat) const;
};

#endif
