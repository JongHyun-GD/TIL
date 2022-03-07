#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string _target;

	PresidentialPardonForm();
public:
	PresidentialPardonForm(std::string &target);
	PresidentialPardonForm(PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(PresidentialPardonForm &other);

	const std::string& getTarget() const;

	void execute(Bureaucrat &bureaucrat) const;
};

#endif
