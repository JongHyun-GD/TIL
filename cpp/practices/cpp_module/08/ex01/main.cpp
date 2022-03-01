#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	std::cout << "<==== Basic test ====>" << std::endl;
	Span sp(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortestSpan:\t" << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan:\t" << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "<==== Large test ====>" << std::endl;
	Span lsp(100000);
	srand(time(NULL));
	for (int i=0; i<100000; ++i)
		lsp.addNumber(rand() % 10);
	std::cout << "shortestSpan:\t" << lsp.shortestSpan() << std::endl;
	std::cout << "longestSpan:\t" << lsp.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "<==== Deep Copy Test ====>" << std::endl;
	Span orig(10);
	orig.addNumber(1);
	orig.addNumber(2);
	orig.addNumber(3);
	orig.addNumber(4);
	orig.addNumber(5);

	Span clone(orig);
	clone.addNumber(6);
	std::cout << "shortestSpan:\t" << orig.shortestSpan() << std::endl;
	std::cout << "longestSpan:\t" << orig.longestSpan() << std::endl;
	std::cout << "shortestSpan:\t" << clone.shortestSpan() << std::endl;
	std::cout << "longestSpan:\t" << clone.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "<==== Exception Test ====>" << std::endl;
	Span sp1(2);
	try {
		sp1.addNumber(5);
		sp1.addNumber(4);
		sp1.addNumber(3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Span sp2(100);
	try {
		sp2.shortestSpan();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp2.addNumber(1);
		sp2.shortestSpan();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp2.longestSpan();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "<==== Limit Test ====>" << std::endl;
	Span sp3(2);
	sp3.addNumber(-2147483648);
	sp3.addNumber(2147483647);
	std::cout << "shortestSpan:\t" << sp3.shortestSpan() << std::endl;
	std::cout << "longestSpan:\t" << sp3.longestSpan() << std::endl;
	std::cout << std::endl;
}
