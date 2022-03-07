#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T>
class Array
{
private:
	T* _ptr;
	unsigned int _len;
public:
	Array()
		:_len(0) {}
	Array(unsigned int n)
		:_len(n)
	{
		_ptr = new T[n];
	}

	T& operator[](unsigned int i)
	{
		if (i >= _len)
			throw std::exception();
		return _ptr[i];
	}

	Array(Array &other)
		:_len(other.size())
	{
		_ptr = new T[_len];
		for (int i=0; i<other.size(); ++i)
			_ptr[i] = other[i];
	}

	Array& operator=(Array &other)
	{
		_len = other.size();
		_ptr = new T[_len];
		for (int i=0; i<other.size(); ++i)
			_ptr[i] = other[i];
	}

	unsigned int size() const
	{
		return _len;
	}
};

#endif
