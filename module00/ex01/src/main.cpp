#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string input;

	while (true)
	{
		phoneBook.phoneBookPrompt();
		std::cin >> input;

		if (input == ADD)
			phoneBook.addContact(phoneBook.createContact());
		else if (input == SEARCH)
			phoneBook.searchContacts();
		else if (input == EXIT)
			break;
		else
			std::cout << "Invalid Command!" << std::endl;
	}
	std::cout << std::endl << "Goodbye!" << std::endl;

	return (0);
}
