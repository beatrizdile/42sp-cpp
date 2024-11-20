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

static bool isEmptyOrWhitespace(const std::string &line) {
    // Check if the string is empty
    if (line.empty()) {
        return true;
    }

    // Check if all characters are whitespace
    for (std::size_t i = 0; i < line.size(); ++i) {
        if (!std::isspace(static_cast<unsigned char>(line[i]))) {
            return false;
        }
    }

    return true;
}

static bool isValidFilePath(const char* path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0 && S_ISREG(buffer.st_mode));
};

static long double stringToLongDouble(const std::string &str) {
    std::istringstream stream(str);
    stream.imbue(std::locale("C")); // Ensure '.' is used as the decimal separator
    long double result;
    if (stream >> result && stream.eof()) {
        return result;
    }
    throw std::invalid_argument("Error: invalid number => ");
}

static std::map<std::string, long double>& loadDatabase() {
	static std::map<std::string, long double> localDatabase;
    // check if file is valid
	if (!isValidFilePath("data.csv"))
		throw std::invalid_argument("Error: could not open database.");

	// Open file
	std::ifstream file;
	file.open("data.csv");
	if (file.fail())
		throw std::invalid_argument("Error opening file");

	// Check if header is valid
	std::string line;
    if (!std::getline(file, line)) {
        std::cout << "Error: empty file" << std::endl;
        file.close();
    }

    if (trim(line) != "date,exchange_rate") {
        file.close();
		throw std::invalid_argument("Error: first line of database must be 'date,exchange_rate'");
    }

    while (std::getline(file, line)) {
        std::string date;
        std::string valueStr;

        // Find the position of the separator ','
        std::size_t separatorPos = line.find(',');
        if (separatorPos == std::string::npos) {
            std::cerr << "Error: bad input (missing ',') => " << line << std::endl;
            continue;
        }

        // Extract the date and value parts
        date = line.substr(0, separatorPos);
        valueStr = line.substr(separatorPos + 1);

        // Trim whitespace from date and value parts
        date = trim(date);
        valueStr = trim(valueStr);
        localDatabase[date] = stringToLongDouble(valueStr);
    }

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

BitcoinExchange::BitcoinExchange() : _database() {
};

BitcoinExchange::~BitcoinExchange(){
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database() {
	this->_database = other._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->_database = other._database;
	}
	return *this;
};

BitcoinExchange::BitcoinExchange(const std::string &filename) : _database() {
	// Load database
	this->_database = loadDatabase();

	// Read input file & print output
	generateBitcoinExchange(filename);
};

void BitcoinExchange::calculateExchange(const std::string& targetDate, long double value) {
    // Use lower_bound to find the first date not less than the targetDate
    std::map<std::string, long double>::const_iterator it = _database.lower_bound(targetDate);

    if (it == _database.begin()) {
        return ;
    }

    // Move iterator one step back if it's past the targetDate
    if (it == _database.end() || it->first > targetDate) {
        --it;
    }

    long double exchangeRate = it->second * value;

    std::cout << targetDate << " => " << value << " = " << exchangeRate << std::endl;
}

void BitcoinExchange::generateBitcoinExchange(const std::string &filename) {
	// Check if file is valid
	if (!isValidFilePath(filename.c_str())) {
		throw std::invalid_argument("Error: could not open file.");
	}

	// Open file
	std::ifstream file;
	file.open(filename.c_str());
	if (file.fail()) {
		throw std::invalid_argument("Error opening file");
		return;
	}

	// Check if header is valid
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
        long double value;

        if (isEmptyOrWhitespace(line))
            continue;

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

        // Convert the value string to long double
        std::istringstream doubleStream(valueStr);
        doubleStream.imbue(std::locale("C")); // Ensure '.' is used as the decimal point
        if (!(doubleStream >> value) || !doubleStream.eof()) {
            std::cerr << "Error: invalid number => " << valueStr << std::endl;
            continue;
        }

        // Check if the value is within the desired range
        if (value < 0 || value > 1000) {
            std::cerr << "Error: invalid number => " << valueStr << std::endl;
            continue;
        }

        // Perform the calculation with the long double value
        calculateExchange(date, value);
    }
};
