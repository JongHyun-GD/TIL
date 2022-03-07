#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	Fixed c(10);
	Fixed d(2);
	std::cout << "Fixed c = " << c << std::endl;
	std::cout << "Fixed d = " << d << std::endl;
	std::cout << "c/d = " << c / d << std::endl;
	if (c >= d)
		std::cout << "max(c,d) = " << c << std::endl;

	Fixed e(8);
	Fixed f(0.125f);
	std::cout << "Fixed e = " << e << std::endl;
	std::cout << "Fixed f = " << f << std::endl;
	std::cout << "e/f = " << e / f << std::endl;
	std::cout << "max(e,f) = " << Fixed::max(e, f) << std::endl;
	return 0;
}
