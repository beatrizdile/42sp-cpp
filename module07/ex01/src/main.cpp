#include "iter.hpp"
#include <iostream>

int main()
{
	// printing integers
	int arrInt[] = {1, 2, 3, 4, 5};
	::iter(arrInt, 5, ::printInt);

	// printing doubles
	double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	::iter(doubleArr, 5, ::printDouble);

	// printing strings
	std::string arrStr[] = {"one", "two", "three", "four", "five"};
	::iter(arrStr, 5, ::printStr);

	std::cout << "-------------------------------------------" << std::endl;

	// printing elements
	::iter(arrInt, 5, ::printElement);
	::iter(doubleArr, 5, ::printElement);
	::iter(arrStr, 5, ::printElement);


	return (0);
}
