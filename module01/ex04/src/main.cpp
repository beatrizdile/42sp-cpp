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
	// Check for params
	if (argc != 4) {
		std::cout << "Invalid params!" << std::endl;
		return (0);
	}
	std::string needle 		= argv[2];
	std::string newWord 	= argv[3];


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
	int			index;
	std::string	line;
	while (std::getline(myFile, line))
	{
		index = findSubstring(line, needle);
		if (index == -1)
			replaceFile << line;
		else
		{
			for (int i = 0; i < (int)line.length(); i++)
			{
				if (i == index)
				{
					replaceFile << newWord;
					i += (int)needle.length();

					// Get the next possible match for needle in the same line
					index += findSubstring(line.substr((index + needle.length()),
						((int)line.length() - index)), needle) + (int)needle.length();
				}
				if (i != (int)line.length())
					replaceFile << line[i];
			}
		}
		replaceFile << std::endl;
	}
	myFile.close();
	replaceFile.close();
}
