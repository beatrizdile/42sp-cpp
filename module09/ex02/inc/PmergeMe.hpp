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
#include <utility>

class PmergeMe {
	private:
		PmergeMe();
		PmergeMe& operator=(PmergeMe const & other);
		void parseInput(std::string str);
		std::vector<int> myVector;
		std::deque<int> myDeque;
		void print();
	public:
		~PmergeMe();
		PmergeMe(PmergeMe const & other);
		PmergeMe(std::string str);

		template <typename T>
		static void insertionSort(T &container) {
			for (size_t index = 1; index < container.size(); index++) {
				size_t previus = index - 1;
				std::pair<int, int> currentValue = container[index];
				while (container[previus].second > currentValue.second) {
					container[previus + 1] = container[previus];
					if (previus-- == 0)
						break;
				}
				container[previus + 1] = currentValue;
			}
		}
};

#endif