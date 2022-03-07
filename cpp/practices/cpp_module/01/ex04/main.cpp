#include "replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace [file_name_to_replace] [s1] [s2]\n";
		return (1);
	}

	std::string file_name(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	replace(file_name, s1, s2);

	return (0);
}
