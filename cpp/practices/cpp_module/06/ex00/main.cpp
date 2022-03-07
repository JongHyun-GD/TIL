#include "Caster.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./ex00 [literal_to_cast]" << std::endl;
		return (1);
	}
	Caster caster(argv[1]);
	std::cout << std::fixed;
	std::cout << std::setprecision(1);
	char c = static_cast<char>(caster);
	int i = static_cast<int>(caster);
	float f = static_cast<float>(caster);
	double d = static_cast<double>(caster);
	(void)c, (void)i, (void)f, (void)d;
}
