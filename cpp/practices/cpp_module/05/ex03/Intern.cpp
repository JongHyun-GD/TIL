#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern &other) { (void)other; }

Intern &Intern::operator=(Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

static Form *make_shrubbery(std::string &target)
{
	Form *ptr = new ShrubberyCreationForm(target);
	return ptr;
}

static Form *make_robotomy(std::string &target)
{
	Form *ptr = new RobotomyRequestForm(target);
	return ptr;
}

static Form *make_pardon(std::string &target)
{
	Form *ptr = new PresidentialPardonForm(target);
	return ptr;
}

Form *Intern::makeForm(std::string form, std::string target)
{
	Form *res = NULL;

	std::string form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *(*make_form_funcs[3])(std::string & target) = {make_shrubbery, make_robotomy, make_pardon};

	for (int i=0; i<3; ++i)
	{
		if (form.compare(form_names[i]) == 0)
		{
			res = make_form_funcs[i](target);
			std::cout << "Intern creates " << form_names[i] << " form.\n";
		}
	}

	if (res == NULL)
		throw Intern::UnknownFormException();

	return res;
}

const char* Intern::UnknownFormException::what() const throw()
{
	return "Intern doesn't known that form";
}
