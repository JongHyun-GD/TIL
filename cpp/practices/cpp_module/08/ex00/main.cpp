#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> v(10);
	for (int i=0; i<10; ++i)
		v[i] = i;
	try {
		std::cout << *easyfind(v, 5) << std::endl;
		std::cout << *easyfind(v, 1) << std::endl;
		std::cout << *easyfind(v, 7) << std::endl;
		std::cout << *easyfind(v, -1) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
