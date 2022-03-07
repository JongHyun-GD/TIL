#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	Form();
	const std::string	_name;
	const int			_signGrade;
	const int			_executeGrade;
	bool				_isSigned;
public:
	Form(std::string name, int signGrade, int executeGrade);
	Form(Form &other);
	Form &operator=(Form &other);
	virtual ~Form();

	const std::string&	getName() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	bool				getIsSigned() const;

	void				beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
