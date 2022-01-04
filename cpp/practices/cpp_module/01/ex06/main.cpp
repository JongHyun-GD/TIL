#include "Karen.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./karenFilter [Filter]\n";
		return (1);
	}
	Karen karen(argv[1]);
	karen.complain(argv[1]);
}
