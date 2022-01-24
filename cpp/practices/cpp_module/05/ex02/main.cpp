#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "<==== constructor test ====>" << std::endl;
	Bureaucrat b1("b1", 1);
	std::cout << b1 << std::endl;
	Bureaucrat b40("b40", 40);
	std::cout << b40 << std::endl;
	Bureaucrat b150("b150", 150);
	std::cout << b150 << std::endl << std::endl;

	std::string t1("t1");
	std::string t2("t2");
	std::string t3("t3");

	Form *shrubbery = new ShrubberyCreationForm(t1);
	std::cout << *shrubbery << std::endl;
	Form *robotomy = new RobotomyRequestForm(t2);
	std::cout << *robotomy << std::endl;
	Form *pardon = new PresidentialPardonForm(t3);
	std::cout << *pardon << std::endl;
	std::cout << std::endl;

	std::cout << "<==== shrubbery creation form test ====>" << std::endl;
	b150.signForm(*shrubbery);
	b40.executeForm(*shrubbery);
	b40.signForm(*shrubbery);
	std::cout << *shrubbery << std::endl;
	b40.executeForm(*shrubbery);
	std::cout << std::endl;

	std::cout << "<==== robotomy request form test ====>" << std::endl;
	b150.signForm(*robotomy);
	b40.executeForm(*robotomy);
	b40.signForm(*robotomy);
	std::cout << *robotomy << std::endl;
	b40.executeForm(*robotomy);
	std::cout << std::endl;

	std::cout << "<==== presidential pardon form test ====>" << std::endl;
	b150.signForm(*pardon);
	b40.signForm(*pardon);
	b1.executeForm(*pardon);
	b1.signForm(*pardon);
	std::cout << *pardon << std::endl;
	b1.executeForm(*pardon);
	std::cout << std::endl;

	std::cout << "<==== deconstructor exception test ====>" << std::endl;
	delete shrubbery;
	delete robotomy;
	delete pardon;
}
