#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>
# include <iostream>

template <typename T>
class Array
{
  public:
	Array();
	Array(unsigned int n);
	~Array();
	Array(const Array &other);
	Array &operator=(const Array &other);

	unsigned int size() const;

	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;

  private:
	T *array;
	unsigned int arraySize;
};

#include "Array.tpp"

#endif