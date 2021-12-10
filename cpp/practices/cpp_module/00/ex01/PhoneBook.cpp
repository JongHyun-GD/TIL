#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contacts = new Contact[this->MAX_SIZE];
	this->size = 0;
}

int PhoneBook::add()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "First name: ";
	std::cin >> first_name;
	std::cout << "Last name: ";
	std::cin >> last_name;
	std::cout << "nickname: ";
	std::cin >> nickname;
	std::cout << "Phone number: ";
	std::cin >> phone_number;
	std::cout << "What is your darkest secret?\n";
	std::cin >> darkest_secret;
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
	std::cout << "*----------*----------*----------*----------*\n";
	std::cout << "|first_name| last_name|  nickname|       H.P|\n";
	for (int i = 0; i < this->size; ++i) {
		std::cout << "*----------*----------*----------*----------*\n";
		std::cout << "|" << std::setw(10) << this->contacts[i].getFirstName() << std::setw(0)
				  << "|" << std::setw(10) << this->contacts[i].getLastName() << std::setw(0)
				  << "|" << std::setw(10) << this->contacts[i].getNickname() << std::setw(0)
				  << "|" << std::setw(10) << this->contacts[i].getPhoneNumber() << std::setw(0)
				  << "|\n";
	}
	std::cout << "*----------*----------*----------*----------*\n";

	return 0;
}
