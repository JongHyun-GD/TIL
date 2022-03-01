#include "iter.hpp"
#include <string>
#include <iostream>

template <typename T>
void print(T a)
{
	std::cout << a << std::endl;
}

int main()
{
	std::cout << "<==== int array test ====>\n";
	int a[10] = {-4,-3,-2,-1,0,2,4,6,8,10};
	iter(a, 10, print);
	std::cout << std::endl;
	std::cout << "<==== int array test ====>\n";
	float b[5] = {1.1, -2.2, 3.3, -4.4, 5.5};
	iter(b, 4, print);
	std::cout << std::endl;
	std::cout << "<==== int array test ====>\n";
	std::string c[9] = {"aaaaa", "bbbb", "ccc", "dd", "e", "ff", "ggg", "hhhh", "iiiii"};
	iter(c, 9, print);
}
