#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

class Span
{
private:
	Span();

	std::vector<int> _v;
public:
	Span(unsigned int n);
	Span(Span& other);
	Span& operator=(Span& other);
	virtual ~Span();

	void addNumber(int);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	int getData(unsigned int idx) const;
	size_t getCapacity() const;
	size_t getSize() const;
};

#endif
