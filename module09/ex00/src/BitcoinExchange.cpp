#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
};

BitcoinExchange::~BitcoinExchange(){
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other) {
		// this->_target = other._target;
	}
	return *this;
};

BitcoinExchange::BitcoinExchange(const std::string &filename){
	readData(filename);

	// create a file with the price and date of exchange
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
