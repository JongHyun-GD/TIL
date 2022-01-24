#include "Bureaucrat.hpp"

int main()
{
	std::cout << "<==== constructor test ====>" << std::endl;
	Bureaucrat b1("b1", 1);
	std::cout << b1 << std::endl;
	Bureaucrat b100("b100", 100);
	std::cout << b100 << std::endl;
	Bureaucrat b150("b150", 150);
	std::cout << b150 << std::endl;
	Form f10("f10", 10, 10);
	std::cout << f10 << std::endl;
	Form f120("f120", 120, 120);
	std::cout << f120 << std::endl;
	Form f150("f150", 150, 150);
	std::cout << f150 << std::endl;
	std::cout << std::endl;

	std::cout << "<==== constructor exception test ====>" << std::endl;
	try {
		Form f200("f200", 200, 100);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form fzero("fzero", 0, 100);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "<==== sign form test ====>" << std::endl;
	b1.signForm(f10);
	std::cout << f10 << std::endl;
	b150.signForm(f150);
	std::cout << f150 << std::endl;
	std::cout << std::endl;

	std::cout << "<==== sign form exception test ====>" << std::endl;
	b150.signForm(f120);
}
