#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
};

BitcoinExchange::~BitcoinExchange(){
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
	// this->_target = other._target;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other) {
		// this->_target = other._target;
	}
	return *this;
};

std::string BitcoinExchange::findClosestDate(const std::map<std::string, int>& dateMap, const std::string& targetDate) {
    // Use lower_bound to find the first date not less than the targetDate
    std::map<std::string, int>::const_iterator it = dateMap.lower_bound(targetDate);

    // check if lower_bound points to targetDate exactly or if we need to go to the previous date
    if (it == dateMap.begin()) {
        // if the targetDate is earlier than the first date in the map, there's no earlier date to find
        return it->first;
    }

    // move iterator one step back if it's past the targetDate
    if (it == dateMap.end() || it->first > targetDate) {
        --it;
    }

    return it->first;
}

BitcoinExchange::BitcoinExchange(const std::string &filename){
	// load database
	std::map<std::string, int> dateMap;
	dateMap["2009-01-02"] = 1;
	dateMap["2009-01-05"] = 2;
	dateMap["2009-01-08"] = 3;
	dateMap["2009-01-11"] = 4;
	dateMap["2009-01-14"] = 5;
	dateMap["2009-01-17"] = 6;
	dateMap["2009-01-20"] = 7;
	dateMap["2009-01-23"] = 8;
	dateMap["2009-01-26"] = 9;
	dateMap["2009-01-29"] = 10;
	dateMap["2009-02-01"] = 11;
	dateMap["2009-02-04"] = 12;
	dateMap["2009-02-07"] = 13;
	dateMap["2009-02-10"] = 14;
	dateMap["2009-02-13"] = 15;
	dateMap["2009-02-16"] = 16;
	dateMap["2009-02-19"] = 17;
	dateMap["2009-02-22"] = 18;
	dateMap["2009-02-25"] = 19;
	dateMap["2009-02-28"] = 20;
	dateMap["2009-03-03"] = 21;
	dateMap["2009-03-06"] = 22;
	dateMap["2009-03-09"] = 23;
	dateMap["2009-03-12"] = 24;
	dateMap["2009-03-15"] = 25;
	dateMap["2009-03-18"] = 26;
	dateMap["2009-03-21"] = 27;
	dateMap["2009-03-24"] = 28;
	dateMap["2009-03-27"] = 29;
	dateMap["2009-03-31"] = 30;
	dateMap["2009-04-03"] = 31;
	dateMap["2009-04-06"] = 32;
	dateMap["2009-04-09"] = 33;
	dateMap["2009-04-12"] = 34;
	dateMap["2009-04-15"] = 35;
	dateMap["2009-04-18"] = 36;
	dateMap["2009-04-21"] = 37;

	// read input data
	readData(filename);

	// create output
	std::cout << "findClosestDate: " << findClosestDate(dateMap, "2009-04-20") << std::endl;
};

void BitcoinExchange::readData(const std::string &filename){
	if (!isValidFile(filename.c_str())) {
		throw std::invalid_argument("Error: could not open file.");
	}
	std::cout << "File is valid." << std::endl;
};

bool BitcoinExchange::isValidFile(const char* path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0 && S_ISREG(buffer.st_mode));
};
