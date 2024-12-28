#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <limits>
#include <cstdlib>
#include <string>
#include <sstream>
#include <locale>
#include <utility>
#include <ctime>

class PmergeMe {
	private:
		PmergeMe();
		PmergeMe& operator=(PmergeMe const & other);
		void parseInput(std::string str);
		std::vector<int> myVector;
		std::deque<int> myDeque;
		void printVector();
		void printDeque();
		void sortingVector();
		void sortingDeque();
	public:
		~PmergeMe();
		PmergeMe(PmergeMe const & other);
		PmergeMe(std::string str);

		template <typename T>
		static void insertionSort(T &container) {
			for (size_t index = 1; index < container.size(); index++) {
				size_t previous = index - 1;
				std::pair<int, int> currentValue = container[index];
				while (container[previous].first > currentValue.first) {
					container[previous + 1] = container[previous];
					if (previous-- == 0)
						break;
				}
				container[previous + 1] = currentValue;
			}
		}

		template<typename Container>
		void binarySearch(int value, Container& container) {
			if (container.empty()) {
				container.push_back(value);
				return;
			}

			typedef typename Container::iterator iterator;
			iterator begin = container.begin();
			iterator end = container.end();

			if (value > *(end - 1)) {
				container.push_back(value);
				return;
			}

			if (value < *begin) {
				container.insert(begin, value);
				return;
			}

			iterator pos = std::lower_bound(container.begin(), container.end(), value);

			container.insert(pos, value);
		}

};

#endif