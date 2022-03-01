#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string &target)
	:Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other)
	:Form(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _target(other.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	setIsSigned(other.getIsSigned());
	_target = other.getTarget();
	return *this;
}

const std::string& PresidentialPardonForm::getTarget() const { return _target; }

void PresidentialPardonForm::execute(Bureaucrat &bureaucrat) const
{
	if (getIsSigned() == false)
		throw PresidentialPardonForm::UnsignedFormException();
	else if (getExecuteGrade() < bureaucrat.getGrade())
		throw PresidentialPardonForm::GradeTooLowException();
	else
		std::cout << _target << " has been pardoned by Zafod Beeblebrox.\n";
}
