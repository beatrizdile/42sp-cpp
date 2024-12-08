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
		std::cout << "*it: " << *it << std::endl;

		// check if entire string contains only digits
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
}

void PmergeMe::print() {
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
		std::cout << *it << " ";
}
