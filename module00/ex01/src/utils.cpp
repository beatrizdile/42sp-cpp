#include "Contact.hpp"
#include <iostream>

std::string toLower(std::string str)
{
    for (int i = 0; i < (int)str.size(); i++) {
		str[i] = tolower(str[i]);
	}

	return str;
}

Contact*	createContact()
{
	std::cout << std::endl << "To register a new contact, please complete the following fields: " << std::endl;

	std::string firstName;
	std::cout << "Fist name: " << std::endl;
	std::cin >> firstName;
	
	std::string lastName;
	std::cout << "Last name: " << std::endl;
	std::cin >> lastName;

	std::string nickname;
	std::cout << "Nickname: " << std::endl;
	std::cin >> nickname;

	std::string phone;
	std::cout << "Phone: " << std::endl;
	std::cin >> phone;

	std::string darkestSecret;
	std::cout << "Darkest Secret: " << std::endl;
	std::cin >> darkestSecret;

	Contact* newContact = new Contact(firstName, lastName, nickname, phone, darkestSecret);
	std::cout << "Contact created at " << newContact << std::endl;
	return (newContact);
}
