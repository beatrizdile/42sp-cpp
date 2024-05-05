#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <string>

#define ADD "add"
#define SEARCH "search"
#define EXIT "exit"
#define MAX_CONTACTS_SIZE 8
#define DASH "-------------------------------------------------"

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phone;
		std::string darkestSecret;
	public:
		Contact(const std::string& first, const std::string& last,
        const std::string& nick = "", const std::string& phone = "",
        const std::string& secret = "");
		~Contact();
		void displayContactRow(size_t index);
		void displayContact(void);

		std::string getFirstName() const { return firstName; }
		std::string getLastName() const { return lastName; }
		std::string getNickname() const { return nickname; }
		std::string getPhone() const { return phone; }
		std::string getDarkestSecret() const { return darkestSecret; }
};

#endif