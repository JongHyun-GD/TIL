#include "Span.hpp"

Span::Span(unsigned int n)
{
	_v = std::vector<int>();
	_v.reserve(n);
}

Span::Span(Span &other)
{
	size_t cap = other.getCapacity();
	_v = std::vector<int>();
	_v.reserve(cap);
	for (unsigned int i=0; i < other.getSize(); ++i) {
		_v.push_back(other.getData(i));
	}
}

Span& Span::operator=(Span& other)
{
	size_t cap = other.getCapacity();
	_v = std::vector<int>();
	_v.reserve(cap);
	for (unsigned int i=0; i < other.getSize(); ++i) {
		_v.push_back(other.getData(i));
	}
	return *this;
}

Span::~Span() {
	_v.clear();
}

void Span::addNumber(int num)
{
	if (_v.size() == _v.capacity())
		throw std::out_of_range("Span is full now");
	else
		_v.push_back(num);
}

unsigned int Span::shortestSpan()
{
	if (_v.size() <= 1)
	{
		throw std::out_of_range("Span doesn't have enough numbers");
		return 0;
	}
	else
	{
		std::sort(_v.begin(), _v.end());
		unsigned int diff = _v[1] - _v[0];
		for (unsigned int i=0; i<_v.size()-1; ++i) {
			diff = std::min((unsigned int)(_v[i+1] - _v[i]), diff);
		}
		return diff;
	}
}

unsigned int Span::longestSpan()
{
	if (_v.size() <= 1)
	{
		throw std::out_of_range("Span doesn't have enough numbers");
		return 0;
	}
	else
	{
		std::sort(_v.begin(), _v.end());
		return (unsigned int)(_v[_v.size()-1] - _v[0]);
	}
}

int Span::getData(unsigned int idx) const
{
	if (idx >= _v.size()) {
		throw std::out_of_range("index overflow");
		return 0;
	}
	else
		return _v[idx];
}

size_t Span::getCapacity() const { return _v.capacity(); }

size_t Span::getSize() const { return _v.size(); }
