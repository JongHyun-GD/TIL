#include <string>
#include <iostream>

int main(void)
{
	std::string str("HI THIS IS BRAIN");
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The address of the string:\t" << &str << "\n";
	std::cout << "The address with stringPTR:\t" << stringPTR << "\n";
	std::cout << "The address with stringREF:\t" << &stringREF << "\n";

	std::cout << "Display with stringPTR:\t" << *stringPTR << "\n";
	std::cout << "Display with stringREF:\t" << stringREF << "\n";
}
