#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(){
	std::cout << "Welcome to crappy awesome PhoneBook!" << std::endl;
}

PhoneBook::~PhoneBook(){ return; }

void PhoneBook::phoneBookPrompt(){
	std::cout << std::endl << "Please, select one of the following commands:" << std::endl 
	<< "ADD	- to register a new contact" << std::endl 
	<< "SEARCH	- to search for a contact" << std::endl 
	<< "EXIT	- to quit the program" << std::endl;
}

Contact PhoneBook::createContact()
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

	return (Contact(firstName, lastName, nickname, phone, darkestSecret));
}

void PhoneBook::addContact(const Contact& contact){
	contacts.push_back(contact);
	std::cout << std::endl << "The following contact was added to the PhoneBook:" << std::endl;
	std::cout << "Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone: " << contact.getPhone() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::printAllContacts() {
	for (std::size_t i = 0; i < contacts.size(); i++) {
		std::cout << std::endl << &contacts[i] << std::endl;
		std::cout << "First Name: " << contacts[i].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[i].getLastName() << std::endl;
		std::cout << std::endl;
	}
}