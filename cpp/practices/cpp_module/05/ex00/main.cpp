#include "Bureaucrat.hpp"

int main()
{
	std::cout << "<==== constructor test ====>" << std::endl;
	Bureaucrat b1("b1", 42);
	std::cout << b1 << std::endl;
	Bureaucrat b10("b10", 1);
	std::cout << b10 << std::endl;
	Bureaucrat b11("b11", 150);
	std::cout << b11 << std::endl;
	std::cout << std::endl;

	std::cout << "<==== constructor exception test ====>" << std::endl;
	try { Bureaucrat b3("b3", 0); }
	catch (std::exception& e) {std::cout << e.what() << std::endl;}
	try { Bureaucrat b4("b4", -1234234); }
	catch (std::exception& e) {std::cout << e.what() << std::endl;}
	try { Bureaucrat b5("b5", 151); }
	catch (std::exception& e) {std::cout << e.what() << std::endl;}
	try { Bureaucrat b6("b6", 1234); }
	catch (std::exception& e) {std::cout << e.what() << std::endl;}
	std::cout << std::endl;

	std::cout << "<==== increment/decrement test ====>" << std::endl;
	std::cout << b1 << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl;
	b1.decrementGrade();
	std::cout << b1 << std::endl;
	b1.decrementGrade();
	std::cout << b1 << std::endl;
	std::cout << std::endl;

	std::cout << "<==== increment/decrement exception test ====>" << std::endl;
	try { b10.incrementGrade(); }
	catch (std::exception& e) {std::cout << e.what() << std::endl;}
	try { b11.decrementGrade(); }
	catch (std::exception& e) {std::cout << e.what() << std::endl;}

}
