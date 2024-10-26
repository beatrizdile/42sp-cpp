#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	// create container
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;

	// try to find element in empty container
	try {
		::easyFind(vec, 4);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		::easyFind(lst, 4);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		::easyFind(deq, 4);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "--------------------------------" << std::endl;

	// fill container
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);
		lst.push_back(i);
		deq.push_back(i);
	}

	// find element in container
	std::vector<int>::const_iterator vecResult = ::easyFind(vec, 4);
	std::list<int>::const_iterator lstResult = ::easyFind(lst, 4);
	std::deque<int>::const_iterator deqResult = ::easyFind(deq, 4);

	std::cout << "Element found in vector: " << *vecResult << std::endl;
	std::cout << "Element found in list: " << *lstResult << std::endl;
	std::cout << "Element found in deque: " << *deqResult << std::endl;

	return (0);
}
