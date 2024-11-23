#include "RPN.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cerr << "Error: must take a string as argument" << std::endl;
		return 1;
	}

	try {
		RPN rpn(argv[1]);
		std::cout << rpn.getResult() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
