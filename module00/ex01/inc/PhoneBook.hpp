#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <Contact.hpp>
#include <vector>

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void phoneBookPrompt();
		void addContact(const Contact& contact);
		Contact createContact();
		void printAllContacts();
	private:
		std::vector<Contact> contacts;

};

#endif