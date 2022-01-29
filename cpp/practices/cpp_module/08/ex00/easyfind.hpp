#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

template<typename T>
const typename T::const_iterator easyfind(const T &container, int val)
{
	typename T::const_iterator s = container.begin();
	typename T::const_iterator e = container.end();
	typename T::const_iterator res = std::find(s, e, val);
	if (res == e)
		throw std::out_of_range("Can not find value");
	else
		return res;
}

#endif
