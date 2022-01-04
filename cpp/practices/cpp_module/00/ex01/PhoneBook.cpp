#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contacts = new Contact[this->MAX_SIZE];
	this->size = 0;
}

bool PhoneBook::is_number(std::string &str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

int PhoneBook::add()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "First name: ";
	if (std::getline(std::cin, first_name).eof()) return (1);
	std::cout << "Last name: ";
	if (std::getline(std::cin, last_name).eof()) return (1);
	std::cout << "nickname: ";
	if (std::getline(std::cin, nickname).eof()) return (1);
	std::cout << "Phone number: ";
	if (std::getline(std::cin, phone_number).eof()) return (1);
	if (this->is_number(phone_number) == false)
	{
		std::cout << "[Error] Phone Number has to be a combination of numbers\n";
		return (0);
	}
	std::cout << "What is your darkest secret?\n";
	if (std::getline(std::cin, darkest_secret).eof()) return (1);
	if (this->size < this->MAX_SIZE) {
		this->contacts[this->size].assign(first_name, last_name, nickname, phone_number, darkest_secret);
		this->size++;
	}
	else {
		for (int i = 0; i < this->MAX_SIZE - 1; ++i) {
			this->contacts[i].assign(&(this->contacts[i+1]));
		}
		this->contacts[this->MAX_SIZE - 1].assign(first_name, last_name, nickname, phone_number, darkest_secret);
	}
	return 0;
}

int PhoneBook::search()
{
	if (size == 0)
	{
		std::cout << "[Error] There is not a available contacts!\n";
		return (0);
	}
	std::cout << "*----------*----------*----------*----------*\n";
	std::cout << "|     index|first_name| last_name|  nickname|\n";
	for (int i = 0; i < this->size; ++i) {
		std::cout << "*----------*----------*----------*----------*\n";
		std::cout << "|" << std::setw(10) << i << std::setw(0)
				  << "|" << std::setw(10) << this->contacts[i].getFirstName() << std::setw(0)
				  << "|" << std::setw(10) << this->contacts[i].getLastName() << std::setw(0)
				  << "|" << std::setw(10) << this->contacts[i].getNickname() << std::setw(0)
				  << "|\n";
	}
	std::cout << "*----------*----------*----------*----------*\n";
	std::cout << "Enter index to inspect: ";

	int index;
	std::cin >> index;
	if (std::cin.fail()) {
		std::cerr << "Invalid index!\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		return (0);
	}
	if (index < 0 || index >= this->size)
		std::cerr << "Invalid index!\n";
	else {
		std::cout << "First name: " << this->contacts[index].getFirstName() << "\n";
		std::cout << "Last name: " << this->contacts[index].getLastName() << "\n";
		std::cout << "Nickname: " << this->contacts[index].getNickname() << "\n";
		std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << "\n";
		std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << "\n";
	}
	std::cin.clear();
	std::cin.ignore(256, '\n');
	return 0;
}
