#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	std::string _target;

	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string &target);
	RobotomyRequestForm(RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm &other);

	const std::string& getTarget() const;

	void execute(Bureaucrat &bureaucrat) const;
};

#endif
