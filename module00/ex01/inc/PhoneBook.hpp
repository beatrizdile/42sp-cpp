#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <Contact.hpp>
#include <vector>

# define MAX_CONTACTS_SIZE 8

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void phoneBookPrompt();
		void addContact(const Contact& contact);
		Contact createContact();
		void printAllContacts();
		void searchContacts();
	private:
		std::vector<Contact> contacts;
		size_t contactsCount;
};

#endif