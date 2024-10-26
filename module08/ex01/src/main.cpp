#include "Span.hpp"
#include <iostream>

int main()
{
	Span span(5);

	std::cout << "------------ test with empty span -----------" << std::endl;
	try {
		std::cout << "shortestSpan: " << span.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	span.addNumber(5);
	std::cout << "------------ test with span of only one number -----------" << std::endl;
	try {
		std::cout << "shortestSpan: " << span.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "------------ simple test -----------" << std::endl;
	span.addNumber(3);
	span.addNumber(7);
	span.addNumber(9);
	span.addNumber(10);

	std::cout << "shortestSpan: " << span.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << span.longestSpan() << std::endl;

	std::cout << "------------ test add more then what's allowed -----------" << std::endl;
	try {
		span.addNumber(3);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "------------ test with 10000 items -----------" << std::endl;

	std::vector<int> vec(10000);
	for (size_t i = 0; i < 10000; i++)
		vec[i] = i;
	
	span.assign(vec.begin(), vec.end());

	std::cout << "shortestSpan: " << span.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << span.longestSpan() << std::endl;

	return (0);
}
