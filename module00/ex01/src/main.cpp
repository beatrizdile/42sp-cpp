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
			phoneBook.addContact(phoneBook.createContact());
		else if (inputInLower == SEARCH)
			phoneBook.printAllContacts();
		else if (inputInLower == EXIT)
			break;
		else
			std::cout << "Invalid Command!" << std::endl;
	}
	std::cout << "Goodbye!" << std::endl;

	return (0);
}
