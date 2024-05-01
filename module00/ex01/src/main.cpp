#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

# define ADD "add"
# define SEARCH "search"
# define EXIT "exit"

std::string toLower(std::string str)
{
    for (int i = 0; i < (int)str.size(); i++) {
		str[i] = tolower(str[i]);
	}

	return str;
}

int main()
{
	PhoneBook phoneBook;
	std::string input;

	while (true)
	{
		phoneBook.phoneBookPrompt();
		std::cin >> input;
		std::string inputInLower = toLower(input);

		if (inputInLower == ADD)
			std::cout << "valid command!\n\n";
		else if (inputInLower == SEARCH)
			std::cout << "valid command!\n\n";
		else if (inputInLower == EXIT)
			break;
		else
			std::cout << "Invalid Command!" << std::endl;
	}

	return (0);
}

