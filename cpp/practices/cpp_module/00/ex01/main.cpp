#include "main.hpp"

int main(void)
{
	int err = 0;
	std::string command;
	PhoneBook *phoneBook;

	phoneBook = new PhoneBook();
	std::cout << "ADD / SEARCH / EXIT\n";
	while (1)
	{
		std::cout << "Enter command: ";
		if (std::getline(std::cin, command).eof()) {
			break;
		}
		if (command.compare("ADD") == 0)
			err = phoneBook->add();
		else if (command.compare("SEARCH") == 0)
			err = phoneBook->search();
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Invalid command (ADD / SEARCH / EXIT)\n";
		if (err) break;
	}
	std::cout << "bye bye~\n";
}
