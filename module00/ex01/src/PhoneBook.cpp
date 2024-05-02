#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(){
	std::cout << "Welcome to crappy awesome PhoneBook!" << std::endl;
}

PhoneBook::~PhoneBook(){
	// for (std::size_t i = 0; i < contacts.size(); i++) {
	// 	delete &contacts[i];
	// }
}

void PhoneBook::phoneBookPrompt(){
	std::cout << std::endl << "Please, select one of the following commands:" << std::endl 
	<< "ADD	- to register a new contact" << std::endl 
	<< "SEARCH	- to search for a contact" << std::endl 
	<< "EXIT	- to quit the program" << std::endl;
}

void PhoneBook::addContact(const Contact& contact){
	contacts.push_back(contact);
	std::cout << std::endl << "The following contact was added to the PhoneBook:" << std::endl;
	std::cout << "Address: " << &contact << std::endl;
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