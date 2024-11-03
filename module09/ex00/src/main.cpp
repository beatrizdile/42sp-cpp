#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	// Your program must take a file as argument.
	if (argc != 2) {
		std::cerr << "Usage: ./bitcoin [filename]" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange exchange(argv[1]);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

	// Each line in this file must use the following format: "date | value"
	// A valid date will always be in the following format: Year-Month-Day
	// A valid value must be either a float or a positive integer, between 0 and 1000.
}
