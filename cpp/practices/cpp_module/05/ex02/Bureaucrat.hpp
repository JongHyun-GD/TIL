#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	Bureaucrat();
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat &other);
	Bureaucrat &operator=(Bureaucrat &other);
	virtual ~Bureaucrat();

	const std::string&	getName() const;
	int					getGrade() const;

	void				decrementGrade();
	void				incrementGrade();
	void				signForm(Form &form);
	void				executeForm(Form const & form);

	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
