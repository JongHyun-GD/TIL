#include "Contact.hpp"

Contact::Contact()
{
	return;
};

void Contact::assign(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

void Contact::assign(Contact *newContact)
{
	this->first_name = newContact->first_name;
	this->last_name = newContact->last_name;
	this->nickname = newContact->nickname;
	this->phone_number = newContact->phone_number;
	this->darkest_secret = newContact->darkest_secret;
};

std::string Contact::getFirstName()
{
	if (this->first_name.length() <= 10)
		return this->first_name;
	else {
		std::string output = this->first_name.substr(0, 10);
		output[9] = '.';
		return output;
	}
}

std::string Contact::getLastName()
{
	if (this->last_name.length() <= 10)
		return this->last_name;
	else {
		std::string output = this->last_name.substr(0, 10);
		output[9] = '.';
		return output;
	}
}

std::string Contact::getNickname()
{
	if (this->nickname.length() <= 10)
		return this->nickname;
	else {
		std::string output = this->nickname.substr(0, 10);
		output[9] = '.';
		return output;
	}
}

std::string Contact::getPhoneNumber()
{
	if (this->phone_number.length() <= 10)
		return this->phone_number;
	else {
		std::string output = this->phone_number.substr(0, 10);
		output[9] = '.';
		return output;
	}
}
