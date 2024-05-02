#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>

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
			phoneBook.addContact(*createContact());
		else if (inputInLower == SEARCH)
			std::cout << "valid command!\n";
		else if (inputInLower == EXIT)
			break;
		else
			std::cout << "Invalid Command!" << std::endl;
	}
	// phoneBook.printAllContacts();

	return (0);
}

// phone error handling