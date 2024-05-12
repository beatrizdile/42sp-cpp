#include <iostream>
#include <fstream>
#include <cstring>

int findSubstring(std::string haystack, std::string needle) 
{
	int haystackLen = haystack.length();
	int needleLen = needle.length();

	for (int i = 0; i <= haystackLen - needleLen; ++i) {
		int j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0') {
			j++;
		}

		if (needle[j] == '\0') {
			return i;
		}
	}

	return -1;
}

int main(int argc, char** argv)
{
	// Check num of params
	if (argc != 4) {
		std::cout << "Invalid params!" << std::endl;
		return (0);
	}

	// Open/Create files
	std::fstream myFile;
	myFile.open(argv[1], std::ios::in);
	if (!myFile.is_open()) 
	{
		std::cerr << "Error opening file!" << std::endl;
		return (0);
	}

	std::fstream replaceFile;
	replaceFile.open(strcat(argv[1], ".replace"), std::ios::out);
	if (!replaceFile.is_open()) 
	{
		std::cerr << "Error opening file!" << std::endl;
		return (0);
	}

	// Add content to the ".replace" file
	std::string line;
	while (std::getline(myFile, line)){
		replaceFile << line << std::endl;
	}

	myFile.close();
	replaceFile.close();
}
