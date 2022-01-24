#include "Form.hpp"

Form::Form(std::string name, int signGrade, int executeGrade)
	:_name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (_signGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form &other)
	:_name(other.getName()), _signGrade(other.getSignGrade()), \
	_executeGrade(other.getExecuteGrade()), _isSigned(other.getIsSigned()) {}

Form& Form::operator=(Form &other)
{
	_isSigned = other.getIsSigned();
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const { return _name; }

int Form::getSignGrade() const { return _signGrade; }

int Form::getExecuteGrade() const { return _executeGrade; }

bool Form::getIsSigned() const { return _isSigned; }

void Form::setIsSigned(bool isSigned) {_isSigned = isSigned; }

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	else
		_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char* Form::UnsignedFormException::what() const throw()
{
	return "the form is not signed yet";
}

std::ostream& operator<< (std::ostream &out, Form const &form)
{
	out << form.getName() << ", form sign_grade " << form.getSignGrade() << ", execute_grade " << form.getExecuteGrade() << ", and is ";
	if (form.getIsSigned())
		out << "signed.";
	else
		out << "not signed yet.";
	return out;
}
