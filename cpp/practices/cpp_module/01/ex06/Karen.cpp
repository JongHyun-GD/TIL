#include "Karen.hpp"

void Karen::debug()
{
	std::cout << "[DEBUG]\n";
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n";
}

void Karen::info()
{
	std::cout << "[INFO]\n";
	std::cout << "I cannot believe adding extra bacon cost more money.\n";
	std::cout << "You don’t put enough! If you did I would not have to ask for it!\n";
}

void Karen::warning()
{
	std::cout << "[WARNING]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I’ve been coming here for years and you just started working here last month.\n";
}

void Karen::error()
{
	std::cout << "[ERROR]\n";
	std::cout << "This is unacceptable, I want to speak to the manager now.\n";
}

std::string Karen::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};


Karen::Karen(std::string filter)
{
	this->filter_level = -1;
	for (int i = 0; i < 4; ++i)
		if (this->levels[i] == filter)
			this->filter_level = i;
}

void Karen::complain(std::string level)
{
	void (Karen::*funcs[4])() = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

	switch (filter_level)
	{
	case -1:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	case 0:
		(this->*funcs[0])();
	case 1:
		(this->*funcs[1])();
	case 2:
		(this->*funcs[2])();
	case 3:
		(this->*funcs[3])();
	default:
		break;
	}
}
