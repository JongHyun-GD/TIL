#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "<==== constructor test ====>" << std::endl;
	Bureaucrat b1("b1", 1);
	Intern intern;
	std::cout << std::endl;

	std::cout << "<==== make form test ====>" << std::endl;
	Form* f;

	f = intern.makeForm("shrubbery creation", "tree");
	b1.signForm(*f);
	b1.executeForm(*f);
	delete f;
	std::cout << std::endl;

	f = intern.makeForm("robotomy request", "james");
	b1.signForm(*f);
	b1.executeForm(*f);
	delete f;
	std::cout << std::endl;

	f = intern.makeForm("presidential pardon", "john");
	b1.signForm(*f);
	b1.executeForm(*f);
	delete f;
	std::cout << std::endl;

	std::cout << "<==== make form exception test ====>" << std::endl;
	try {
		f = intern.makeForm("making coffee", "me");
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		f = intern.makeForm("stealing money", "me");
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
