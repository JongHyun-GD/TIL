#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
	std::cout << "<==== constructor test ====>" << std::endl;
	Array<int> arr1(10);
	for (int i=0; i<(int)arr1.size(); ++i) arr1[i] = i;
	for (int i=0; i<(int)arr1.size(); ++i) std::cout << arr1[i] << " ";
	std::cout << std::endl << std::endl;

	Array<float> arr2(20);
	for (int i=0; i<(int)arr2.size(); ++i) arr2[i] = i*0.1f;
	for (int i=0; i<(int)arr2.size(); ++i) std::cout << arr2[i] << " ";
	std::cout << std::endl << std::endl;

	Array<std::string> arr3(3);
	arr3[0] = "park";
	arr3[1] = "jong";
	arr3[2] = "hyun";
	for (int i=0; i<(int)arr3.size(); ++i) std::cout << arr3[i] << " ";
	std::cout << std::endl << std::endl;

	std::cout << "<==== indexing exception test ====>" << std::endl;
	try {
		std::cout << arr1[10] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << arr2[-1] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << arr3[200] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}
