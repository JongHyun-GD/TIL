#include "whatever.hpp"
#include <iostream>

int main()
{
	std::cout << "<==== swap test ====>" << std::endl;
	int a = -314, b = 42;
	std::cout << "before: " << a << ", " << b << std::endl;
	swap(a, b);
	std::cout << " after: " << a << ", " << b << std::endl;
	float e = 1.234f, f = -1.234f;
	std::cout << "before: " << e << ", " << f << std::endl;
	swap(e, f);
	std::cout << " after: " << e << ", " << f << std::endl;
	std::string c = "jong", d = "hyun";
	std::cout << "before: " << c << ", " << d << std::endl;
	swap(c, d);
	std::cout << " after: " << c << ", " << d << std::endl;
	std::cout << std::endl;

	std::cout << "<==== min test ====>" << std::endl;
	int m1 = 213, m2 = 342342;
	std::cout << "min(" << m1 << ", " << m2 << ") == " << min(m1,m2) << std::endl;
	float m3 = 123.123, m4 = 123.234;
	std::cout << "min(" << m3 << ", " << m4 << ") == " << min(m3,m4) << std::endl;
	std::string m5 = "abcd", m6 = "efgh";
	std::cout << "min(" << m5 << ", " << m6 << ") == " << min(m5,m6) << std::endl;
	std::cout << std::endl;

	std::cout << "<==== max test ====>" << std::endl;
	std::cout << "max(" << m1 << ", " << m2 << ") == " << max(m1,m2) << std::endl;
	std::cout << "max(" << m3 << ", " << m4 << ") == " << max(m3,m4) << std::endl;
	std::cout << "max(" << m5 << ", " << m6 << ") == " << max(m5,m6) << std::endl;
}
