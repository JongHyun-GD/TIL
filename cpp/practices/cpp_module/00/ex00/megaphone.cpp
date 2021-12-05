#include <iostream>

void megaphone(int argc, const char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else {
		for (int i = 1; i < argc; ++i) {
			std::cout << argv[i];
		}
		std::cout << "\n";
	}
}

int	main(int argc, char **argv) {
	megaphone(argc, argv);

	return 0;
}
