#include "Span.hpp"

Span::Span() : _n(0), _vec(std::vector<int>()) {}

Span::Span(unsigned int n) : _n(n), _vec(std::vector<int>()) {}

Span::Span(Span const &other) : _n(other._n), _vec(other._vec) {}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_n = other._n;
		_vec = other._vec;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int value)
{
	if (_vec.size() >= _n)
		throw std::runtime_error("Container is full");
	_vec.push_back(value);
}

int Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw std::runtime_error("Not enough elements to calculate span");
	std::sort(_vec.begin(), _vec.end());
	return (_vec[_vec.size() - 1] - _vec[0]);
}

int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw std::runtime_error("Not enough elements to calculate span");
	std::sort(_vec.begin(), _vec.end());
	int min = _vec[1] - _vec[0];
	for (size_t i = 1; i < _vec.size(); i++)
	{
		if (_vec[i] - _vec[i - 1] < min)
			min = _vec[i] - _vec[i - 1];
	}
	return (min);
}

void Span::assign(std::vector<int>::iterator it1, std::vector<int>::iterator it2)
{
	_vec.assign(it1, it2);
	_n = _vec.size();
}
