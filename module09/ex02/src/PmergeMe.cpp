#include "PmergeMe.hpp"

static std::string trim(const std::string& str) {
    if (str.empty())
        return str;

    std::string result = str;
    while (!result.empty() && isspace(result[0]))
        result.erase(0, 1);

    while (!result.empty() && isspace(result[result.length() - 1]))
        result.erase(result.length() - 1, 1);

    return result;
}

static std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::string::size_type start = 0;
    std::string::size_type end = str.find(delimiter);

    while (end != std::string::npos) {
        // only push back non-empty substrings
        if (end > start) {
            result.push_back(str.substr(start, end - start));
        }

        start = end + 1;
        end = str.find(delimiter, start);
    }

    // only push back the last substring if it's not empty
    if (start < str.length()) {
        result.push_back(str.substr(start));
    }

    return result;
}

static int stringToInt(const std::string &str) {
    std::istringstream stream(str);
    stream.imbue(std::locale("C"));
    int result;
    if (stream >> result && stream.eof()) {
        return result;
    }
    throw std::invalid_argument("Could not convert a number in the string to an integer");
}

void PmergeMe::parseInput(std::string str) {
	str = trim(str);

	if (str.empty())
		throw std::invalid_argument("Empty string");

	std::vector<std::string> array = split(str, ' ');

	// check if there are only numbers in the array
	for (std::vector<std::string>::iterator it = array.begin(); it != array.end(); ++it) {
		for (std::string::iterator char_it = it->begin(); char_it != it->end(); ++char_it)
			if (!isdigit(*char_it))
				throw std::invalid_argument("Non digit character in string");
	}

	// check if there are repeated numbers in the array
	for (std::vector<std::string>::iterator it = array.begin(); it != array.end(); ++it) {
		for (std::vector<std::string>::iterator it2 = it + 1; it2 != array.end(); ++it2) {
			if (*it == *it2)
				throw std::invalid_argument("Repeated number in the string");
		}
	}

	// make the string into integers and store them in a vector
	for (std::vector<std::string>::iterator it = array.begin(); it != array.end(); ++it) {
		int num = stringToInt(*it);
		this->myVector.push_back(num);
	}
}

static void removeDuplicates(std::vector<size_t>& sequence) {
    std::sort(sequence.begin(), sequence.end());
    std::vector<size_t>::iterator newEnd = std::unique(sequence.begin(), sequence.end());
    sequence.erase(newEnd, sequence.end());
}

static void fillGaps(std::vector<size_t>& sequence) {
    if (sequence.size() < 2) return;
    
    std::vector<size_t> result;
    result.push_back(sequence[0]);
    for (size_t i = 1; i < sequence.size(); i++) {
        size_t current = sequence[i];
        
		bool alreadyExists = false;
		for (size_t i = 1; i < result.size(); i++) {
			if (result[i] == current)
				alreadyExists = true;
		}

		if (!alreadyExists)
        	result.push_back(current);

		if (i + 1 > sequence.size())
			continue;
        
        if (sequence[i+1] - current > 1) {
			if (result.back() != sequence[i+1])
				result.push_back(sequence[i+1]);

            for (size_t num = sequence[i+1] - 1; num > current; num--) {
                result.push_back(num);
            }
        }
    }
    sequence = result;
}

static std::vector<size_t> generateJacobsthalUpToValue(size_t maxValue) {
	std::vector<size_t> sequence;

	if (maxValue < 0)
		return sequence;

	sequence.push_back(0);

	if (maxValue < 1)
		return sequence;

	sequence.push_back(1);

	bool addedNew = true;
	while (addedNew) {
		addedNew = false;

		size_t next = sequence[sequence.size() - 1] + 2 * sequence[sequence.size() - 2];

		if (next <= maxValue) {
			sequence.push_back(next);
			addedNew = true;
		}
	}

	// jacobsthal sequence
	// [0, 1, 1, 3, 5, 11, 21, 43, 85, 171]
	removeDuplicates(sequence);
	size_t lastJacobsthalNum = sequence.back();

	// now, add any missing indexes in the jacobsthal sequence
	// [0, 1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 21, 20, 19, 18...]
	fillGaps(sequence);

	// add any missing indexes at the end of the sequence
	if (sequence.back() < maxValue) {
		for (size_t i = lastJacobsthalNum + 1; i <= maxValue; i++) {
			sequence.push_back(i);
		}
	}

	return sequence;
}

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const & other) {
	*this = other;
}

PmergeMe& PmergeMe::operator=(PmergeMe const & other) {
	if (this == &other)
		return *this;

	this->myVector = other.myVector;
	this->myDeque = other.myDeque;

	return *this;
}

PmergeMe::PmergeMe(std::string str) {
	parseInput(str);

	std::cout << "Before: ";
	this->print();

	// check if the vector has an odd number of elements, if so, store the straggler
	// 10 9 5 8 2 1 6 7 4 3 0 -> [ 0 ]
	int straggler = -1;
	if (myVector.size() % 2 != 0) {
        straggler = myVector.back();
        myVector.pop_back();
	}

	// divide the vector into pairs and sort each pair
	// (9, 10) (5, 8) (1, 2) (6, 7) (3, 4)
	std::vector<std::pair<int, int> > pairs;

	for (size_t i = 0; i < myVector.size(); i += 2) {
        if (myVector[i] < myVector[i + 1])
            pairs.push_back(std::make_pair(myVector[i], myVector[i + 1]));
        else
            pairs.push_back(std::make_pair(myVector[i + 1], myVector[i]));
    }

	std::cout << "pairs: ";
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		std::cout << "(" << it->first << ", " << it->second << ")";
	std::cout << std::endl;

	// sort all pairs by the second element (which is the greatest one of the pair)
	// (1, 2) (3, 4) (6, 7) (5, 8) (9, 10)
	PmergeMe::insertionSort(pairs);

	std::cout << "pairs: ";
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		std::cout << "(" << it->first << ", " << it->second << ")";
	std::cout << std::endl;

	// rebuild the vector that contains all weakest numbers of each pair
    myVector.clear();
    myVector.reserve((pairs.size() * 2) + (straggler != -1 ? 1 : 0)); // adding extra space for straggler if needed
    for (size_t i = 0; i < pairs.size(); i++) {
        myVector.push_back(pairs[i].first);
    }

	std::cout << "weakest of each pair: ";
	this->print();

	// generate the jacobsthal sequence
	std::vector<size_t> jacobsthal = generateJacobsthalUpToValue(pairs.size() - 1);
	std::cout << "generated jacobsthal sequence: ";
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        std::cout << jacobsthal[i] << " ";
    }
    std::cout << std::endl;

	// access the pairs based on the generated jacobsthal sequence
	// insert the strongest number of the pair into our vector using binary search
	for (std::vector<size_t>::iterator it = jacobsthal.begin(); it != jacobsthal.end(); ++it) {
		int value = pairs[*it].second;
		std::cout << "value: " << value << std::endl;
		PmergeMe::binarySearch(value, this->myVector);
	}

	// if there's a straggler, we also insert it using binary search
	PmergeMe::binarySearch(straggler, this->myVector);
	std::cout << "result: ";
	this->print();

}

void PmergeMe::print() {
	for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}