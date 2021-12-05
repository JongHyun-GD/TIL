#include "main.hpp"

int main(void)
{
	std::string command;
	PhoneBook *phoneBook;

	phoneBook = new PhoneBook();
	while (1)
	{
		std::cout << "command: ";
		std::cin >> command;

		if (command.compare("ADD") == 0)
			phoneBook->add();
		else if (command.compare("SEARCH") == 0)
			phoneBook->search();
		else if (command.compare("EXIT") == 0)
			break ;
		else
			cout << "Invalid command (ADD / SEARCH / EXIT)\n";
	}
	std::cout << "bye bye~\n";
}
