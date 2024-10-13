#include <stdexcept>

template <typename T>
Array<T>::Array()
	: array(NULL), arraySize(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
	: array(new T[n]()), arraySize(n)
{
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
Array<T>::Array(const Array<T> &other)
	: array(new T[other.arraySize]()), arraySize(other.arraySize)
{
	for (unsigned int i = 0; i < arraySize; i++)
	{
		array[i] = other.array[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] array;
		arraySize = other.arraySize;
		array = new T[arraySize];
		for (unsigned int i = 0; i < arraySize; i++)
		{
			array[i] = other.array[i];
		}
	}
	return (*this);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (arraySize);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index < arraySize)
	{
		return (array[index]);
	}
	throw std::out_of_range("Invalid index");
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index < arraySize)
	{
		return (array[index]);
	}
	throw std::out_of_range("Invalid index");
}