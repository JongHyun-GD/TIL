#include "Karen.hpp"

void Karen::debug()
{
	std::cout << "Debug...\n";
}

void Karen::info()
{
	std::cout << "Info...\n";
}

void Karen::warning()
{
	std::cout << "Warning...\n";
}

void Karen::error()
{
	std::cout << "Error...\n";
}

Karen::Karen()
{
	this->tc[0].str = "DEBUG";
	this->tc[0].func = &Karen::debug;
	this->tc[1].str = "INFO";
	this->tc[1].func = &Karen::info;
	this->tc[2].str = "WARNING";
	this->tc[2].func = &Karen::warning;
	this->tc[3].str = "ERROR";
	this->tc[3].func = &Karen::error;
}

void Karen::complain(std::string level)
{
	for (int i = 0; i < 4; ++i)
		if (this->tc[i].str.compare(level) == 0)
			(this->*tc[i].func)();
}
