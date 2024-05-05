#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void phoneBookPrompt();
		void addContact(const Contact& contact);
		Contact createContact();
		void searchContacts();
	private:
		std::vector<Contact> contacts;
		size_t contactsCount;
		void printHeader();
};

#endif