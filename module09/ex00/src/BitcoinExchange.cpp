#include "BitcoinExchange.hpp"

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

double stringToDouble(const std::string &str) {
    std::istringstream stream(str);
    double result;
    if (stream >> result && stream.eof()) {
        return result;
    }
    throw std::invalid_argument("Invalid input string");
}

static std::map<std::string, int>& loadDatabase() {
	static std::map<std::string, int> localDatabase;
    // check if file is valid
	if (!isValidFilePath("data.csv"))
		throw std::invalid_argument("Error: could not open database.");

	// open file
	std::ifstream file;
	file.open("data.csv");
	if (file.fail())
		throw std::invalid_argument("Error opening file");

	// check if header is valid
	std::string line;
    if (!std::getline(file, line)) {
        std::cout << "Error: empty file" << std::endl;
        file.close();
    }

    if (trim(line) != "date,exchange_rate") {
        file.close();
		throw std::invalid_argument("Error: first line of database must be 'date,exchange_rate'");
    }
        std::cout << "-------DATABASE-------" << std::endl;

    while (std::getline(file, line)) {
        std::string date;
        std::string valueStr;

        // find the position of the separator ','
        std::size_t separatorPos = line.find(',');
        if (separatorPos == std::string::npos) {
            std::cerr << "Error: bad input (missing ',') => " << line << std::endl;
            continue;
        }

        // extract the date and value parts
        date = line.substr(0, separatorPos);
        valueStr = line.substr(separatorPos + 1);

        // trim whitespace from date and value parts
        date = trim(date);
        valueStr = trim(valueStr);
        localDatabase[date] = stringToDouble(valueStr);
        std::cout << date << " | " << localDatabase[date] << std::endl;
    }

	return localDatabase;
}

static bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool isValidDate(const std::string &date) {
    // extract year, month, and day from the date string
    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        return false;
    }

    // check valid year range
    if (year < 0) return false;

    // check if month is valid
    if (month < 1 || month > 12) return false;

    // define the number of days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // adjust for leap years
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    // check if the day is valid for the given month
    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
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

void BitcoinExchange::calculateExchange(const std::map<std::string, int>& dateMap, const std::string& targetDate, double value) {
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

    std::cout << targetDate << " | " << it->second << "*" << _database.find(targetDate)->second << std::endl;
}

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
        double value;

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

        // make the value into a double
        std::istringstream doubleStream(valueStr);
        if (!(doubleStream >> value) || !doubleStream.eof())
            std::cerr << "Error: invalid number => " << valueStr << std::endl;

        // check if the value is within the desired range
        if (value < 0 || value > 1000)
            std::cerr << "Error: invalid number => " << value << std::endl;

        calculateExchange(_database, date, value);
	}
};
