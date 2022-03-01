#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

template<typename T>
const typename T::iterator easyfind(T &container, int val)
{
	typename T::iterator s = container.begin();
	typename T::iterator e = container.end();
	typename T::iterator res = std::find(s, e, val);
	if (res == e)
		throw std::out_of_range("Can not find value");
	else
		return res;
}

#endif
