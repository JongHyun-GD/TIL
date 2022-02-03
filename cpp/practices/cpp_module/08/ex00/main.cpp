#include "easyfind.hpp"
#include <vector>
#include <iterator>
#include <deque>
#include <list>

template<typename C>
void test(C& container, int value)
{
	try {
		typename C::iterator iter = easyfind(container, value);
		std::cout << "Value " << value << " found on index " << std::distance(container.begin(), iter) << ".\n";
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	int arr[] = {4, 1, 2, 3, 5, 5, 5, 6, 5, 7};
	std::vector<int> v(arr, arr + 10);
	std::deque<int> dq(arr, arr+10);
	std::list<int> li(arr, arr+10);

	std::cout << "<==== basic test ====>\n";
	test(v, 5);
	test(dq, 5);
	test(li, 5);
	std::cout << std::endl;

	std::cout << "<==== exception test ====>\n";
	test(v, -1);
	test(dq, 10);
	test(li, 99);
}
