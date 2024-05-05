#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	std::cout << "Welcome to crappy awesome PhoneBook!" << std::endl;
	contactsCount = 0;
}

PhoneBook::~PhoneBook(){}

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
	size_t index;

	if (contacts.size() >= MAX_CONTACTS_SIZE) {
		index = contactsCount % MAX_CONTACTS_SIZE;
		contacts[index] = contact;
	}
	else
		contacts.push_back(contact);
	contactsCount++;

	std::cout << std::endl << "The following contact was added to the PhoneBook:" << std::endl;
	std::cout << "Index: " << contacts.size() - 1 << std::endl;
	std::cout << "Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone: " << contact.getPhone() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::printAllContacts() {
	for (std::size_t i = 0; i < contacts.size(); i++) {
		std::cout << "Index: " << i << std::endl;
		std::cout << "First Name: " << contacts[i].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[i].getLastName() << std::endl;
		std::cout << std::endl;
	}
}

void PhoneBook::printHeader() {
	std::cout << "|" << std::setw(10) << "Index" << "|" <<
              std::setw(10) << "First name" << "|" <<
              std::setw(10) << "Last name" << "|" <<
              std::setw(10) << "Nickname" << "|" << std::endl <<
			  DASH << std::endl;
}

void PhoneBook::searchContacts() {
	if (contactsCount == 0) {
		std::cout << std::endl << "No contacts to display." << std::endl;
	}
	else {
		printHeader();
		for (size_t i = 0; i < contacts.size(); i++)
			contacts[i].displayContactRow(i);

		std::cout << std::endl
		<< "Insert the index of the contact to be displayed:" << std::endl;

		unsigned long input;
		std::cin >> input;

		if (input < contactsCount && input < MAX_CONTACTS_SIZE)
			contacts[input].displayContact();
		else
			std::cout << "Invalid index." << std::endl;
	}
}