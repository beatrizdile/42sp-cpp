#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cerr << "Error: must take one string as argument" << std::endl;
		return 1;
	}

	try {
		PmergeMe pmergeM(argv[1]);
		pmergeM.print();
	}
	catch (std::exception & e){
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
}
