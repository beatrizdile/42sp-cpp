#include "Array.hpp"
#include <iostream>

int	main(void)
{
	Array<int> defaultArray;
	std::cout << "Default constructor used: " << defaultArray.size() << std::endl;
	Array<int> newArray(5);
	std::cout << "Constructor with parameters used: " << newArray.size() << std::endl;

	std::cout << std::endl;

	newArray[0] = 10;
	std::cout << "First element of the array was modified: " << newArray[0] << std::endl;
	newArray[1] = 20;
	std::cout << "Second element of the array was modified: " << newArray[1] << std::endl;

	std::cout << std::endl;

	try {
		std::cout << "Trying to access an invalid index" << std::endl << newArray[10] << std::endl;
	}
	catch (const std::out_of_range &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	Array<int> copyArray = newArray;
	std::cout << "Copy constructor used: " << copyArray.size() << std::endl;
	std::cout << "The first element of the first array was copied: " << copyArray[0] << std::endl;

	std::cout << std::endl;

	newArray[0] = 100;
	std::cout << "Modified the first element of the newArray: " << newArray[0] << std::endl;
	std::cout << "The copyArray didn't change, because it was a deep copy: " << copyArray[0] << std::endl;

	return (0);
}
