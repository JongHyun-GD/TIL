#include <iostream>
#include "Data.hpp"

int main()
{
	std::string name1("Sword");
	std::string name2("Shield");

	Data d1(name1, 5, 10.23f, 123.12);
	Data d2(name2, 34, 20.10f, 450.10);

	std::cout << "[BEFORE SERIALIZAION]\n";
	std::cout << &d1;
	std::cout << &d2;
	std::cout << std::endl;

	std::cout << "[SERIALIZING...]\n";
	uintptr_t ui1 = serialize(&d1);
	uintptr_t ui2 = serialize(&d2);
	std::cout << "d1 pointer: " << (uintptr_t)&d1 << std::endl;
	std::cout << "serialized d1 pointer: " << ui1 << std::endl;
	std::cout << "d2 pointer: " << (uintptr_t)&d2 << std::endl;
	std::cout << "serialized d2 pointer: " << (unsigned long)ui2 << std::endl;
	std::cout << std::endl;

	std::cout << "[AFTER SERIALIZAION]\n";
	Data *d_d1 = deserialize(ui1);
	Data *d_d2 = deserialize(ui2);
	std::cout << d_d1;
	std::cout << d_d2;


}
