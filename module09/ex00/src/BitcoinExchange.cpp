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

static bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool isValidDate(const std::string &date) {
    // Extract year, month, and day from the date string
    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        return false;
    }

    // Check valid year range
    if (year < 0) return false;

    // Check if month is valid
    if (month < 1 || month > 12) return false;

    // Define the number of days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust for leap years
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    // Check if the day is valid for the given month
    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

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

static bool isValidFilePath(const char* path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0 && S_ISREG(buffer.st_mode));
};

static bool isInteger(const std::string &valueStr) {
    for (std::size_t i = (valueStr[0] == '-') ? 1 : 0; i < valueStr.size(); ++i) {
        if (!isdigit(valueStr[i])) return false;
    }
    return true;
}

template <typename T>
static void calculateExchange(const std::map<std::string, int>& dateMap, const std::string& targetDate, T value) {
    // use lower_bound to find the first date not less than the targetDate
    std::map<std::string, int>::const_iterator it = dateMap.lower_bound(targetDate);
    (void)value;

    if (it == dateMap.begin()) {
        return ;
    }

    // move iterator one step back if it's past the targetDate
    if (it == dateMap.end() || it->first > targetDate) {
        --it;
    }

}

BitcoinExchange::BitcoinExchange() : _database() {
};

BitcoinExchange::~BitcoinExchange(){
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database() {
	this->_database = other._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		// this->_target = other._target;
	}
	return *this;
};

BitcoinExchange::BitcoinExchange(const std::string &filename) : _database() {
	// load database
	this->_database = loadDatabase();

	// read input file & print output
	generateBitcoinExchange(filename);
};

void BitcoinExchange::generateBitcoinExchange(const std::string &filename) {
	// check if file is valid
	if (!isValidFilePath(filename.c_str())) {
		throw std::invalid_argument("Error: could not open file.");
	}

	// open file
	std::ifstream file;
	file.open(filename.c_str());
	if (file.fail()) {
		throw std::invalid_argument("Error opening file");
		return;
	}

	// check if header is valid
	std::string line;
    if (!std::getline(file, line)) {
        std::cout << "Error: empty file" << std::endl;
        file.close();
        return;
    }

    if (trim(line) != "date | value") {
        file.close();
		throw std::invalid_argument("Error: first line must be 'date | value'");
    }

    while (std::getline(file, line)) {
        std::string date;
        std::string valueStr;

        // Find the position of the separator '|'
        std::size_t separatorPos = line.find('|');
        if (separatorPos == std::string::npos) {
            std::cerr << "Error: bad input (missing '|') => " << line << std::endl;
            continue;
        }

        // Extract the date and value parts
        date = line.substr(0, separatorPos);
        valueStr = line.substr(separatorPos + 1);

        // Trim whitespace from date and value parts
        date = trim(date);
		valueStr = trim(valueStr);

        // Check if the date format is valid (check for 'YYYY-MM-DD')
        if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
            std::cerr << "Error: invalid date format => " << date << std::endl;
            continue;
        }

		// Validate that the date is an actual calendar date
        if (!isValidDate(date)) {
            std::cerr << "Error: invalid calendar date => " << date << std::endl;
            continue;
        }

        // Check if the value is an integer or a decimal
        if (isInteger(valueStr)) {
        	int value;
            std::istringstream intStream(valueStr);
            int intValue;
            if (!(intStream >> intValue) || !intStream.eof()) {
                std::cerr << "Error: invalid number => " << valueStr << std::endl;
                continue;
            }
            value = intValue;

			if (value < 0 || value > 1000) {
				std::cerr << "Error: invalid number => " << value << std::endl;
				continue;
			}

			calculateExchange(_database, date, value);
        } else {
			float value;
            std::istringstream floatStream(valueStr);
            if (!(floatStream >> value) || !floatStream.eof()) {
                std::cerr << "Error: invalid number => " << valueStr << std::endl;
                continue;
            }

			if (value < 0 || value > 1000) {
				std::cerr << "Error: invalid number => " << value << std::endl;
				continue;
			}

			calculateExchange(_database, date, value);			
        }
	}
};
