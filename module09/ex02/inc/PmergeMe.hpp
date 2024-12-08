#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <stdexcept>
#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <cstdlib>
#include <string>
#include <sstream>
#include <locale>

class PmergeMe {
	private:
		PmergeMe();
		PmergeMe& operator=(PmergeMe const & other);
		void parseInput(std::string str);
		std::vector<int> myVector;
		std::deque<int> myDeque;
	public:
		~PmergeMe();
		PmergeMe(PmergeMe const & other);
		PmergeMe(std::string str);
		void print();
};

#endif