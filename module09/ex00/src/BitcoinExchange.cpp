#include "BitcoinExchange.hpp"

static std::map<std::string, int>& loadDatabase() {
	static std::map<std::string, int> localDatabase;

	localDatabase["2009-01-02"] = 1;
	localDatabase["2009-01-05"] = 2;
	localDatabase["2009-01-08"] = 3;
	localDatabase["2009-01-11"] = 4;
	localDatabase["2009-01-14"] = 5;
	localDatabase["2009-01-17"] = 6;
	localDatabase["2009-01-20"] = 7;
	localDatabase["2009-01-23"] = 8;
	localDatabase["2009-01-26"] = 9;
	localDatabase["2009-01-29"] = 10;
	localDatabase["2009-02-01"] = 11;
	localDatabase["2009-02-04"] = 12;
	localDatabase["2009-02-07"] = 13;
	localDatabase["2009-02-10"] = 14;
	localDatabase["2009-02-13"] = 15;
	localDatabase["2009-02-16"] = 16;
	localDatabase["2009-02-19"] = 17;
	localDatabase["2009-02-22"] = 18;
	localDatabase["2009-02-25"] = 19;
	localDatabase["2009-02-28"] = 20;
	localDatabase["2009-03-03"] = 21;
	localDatabase["2009-03-06"] = 22;
	localDatabase["2009-03-09"] = 23;
	localDatabase["2009-03-12"] = 24;
	localDatabase["2009-03-15"] = 25;
	localDatabase["2009-03-18"] = 26;
	localDatabase["2009-03-21"] = 27;
	localDatabase["2009-03-24"] = 28;
	localDatabase["2009-03-27"] = 29;
	localDatabase["2009-03-31"] = 30;
	localDatabase["2009-04-03"] = 31;
	localDatabase["2009-04-06"] = 32;
	localDatabase["2009-04-09"] = 33;
	localDatabase["2009-04-12"] = 34;
	localDatabase["2009-04-15"] = 35;
	localDatabase["2009-04-18"] = 36;
	localDatabase["2009-04-21"] = 37;

	return localDatabase;
}

BitcoinExchange::BitcoinExchange() : _database() {
};

BitcoinExchange::~BitcoinExchange(){
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database() {
	this->_database = other._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other) {
		// this->_target = other._target;
	}
	return *this;
};

BitcoinExchange::BitcoinExchange(const std::string &filename) : _database() {
	// load database
	this->_database = loadDatabase();

	// read input file
	readInputFile(filename);

	// create output
	std::cout << "findClosestDate: " << findClosestDate(_database, "2009-04-20") << std::endl;
};

std::string BitcoinExchange::findClosestDate(const std::map<std::string, int>& dateMap, const std::string& targetDate) {
    // use lower_bound to find the first date not less than the targetDate
    std::map<std::string, int>::const_iterator it = dateMap.lower_bound(targetDate);

    if (it == dateMap.begin()) {
        return it->first;
    }

    // move iterator one step back if it's past the targetDate
    if (it == dateMap.end() || it->first > targetDate) {
        --it;
    }

    return it->first;
}

void BitcoinExchange::readInputFile(const std::string &filename){
	if (!isValidFile(filename.c_str())) {
		throw std::invalid_argument("Error: could not open file.");
	}
};

bool BitcoinExchange::isValidFile(const char* path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0 && S_ISREG(buffer.st_mode));
};


// PARSING input file
// check if date is in a valid format
// check if date is valid
// check if value is a float or a positive integer, between 0 and 1000
