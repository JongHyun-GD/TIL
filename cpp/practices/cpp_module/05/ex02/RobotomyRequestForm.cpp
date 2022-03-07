#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string &target)
	:Form("RobotomyRequestForm", 72, 45), _target(target)
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other)
	:Form(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _target(other.getTarget())
{
	srand(time(NULL));
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
	setIsSigned(other.getIsSigned());
	_target = other.getTarget();
	return *this;
}

const std::string& RobotomyRequestForm::getTarget() const { return _target; }

void RobotomyRequestForm::execute(Bureaucrat &bureaucrat) const
{
	if (getIsSigned() == false)
		throw RobotomyRequestForm::UnsignedFormException();
	else if (getExecuteGrade() < bureaucrat.getGrade())
		throw RobotomyRequestForm::GradeTooLowException();
	else
	{
		std::cout << "DDDDDRRRRRRRRR.... dddddddrrrrrrr.....\n";
		if (rand() % 2 == 0)
			std::cout << _target << " has been robotomized successfully.\n";
		else
			std::cout << _target << " failed to be robotomized.\n";
	}
}
