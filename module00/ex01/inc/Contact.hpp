#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

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

		// Getters
		std::string getFirstName() const { return firstName; }
		std::string getLastName() const { return lastName; }
		std::string getNickname() const { return nickname; }
		std::string getPhone() const { return phone; }
		std::string getDarkestSecret() const { return darkestSecret; }

		// Setters
		void setFirstName(const std::string& newFirstName) { firstName = newFirstName; }
		void setLastName(const std::string& newLastName) { lastName = newLastName; }
		void setNickname(const std::string& newNickname) { nickname = newNickname; }
		void setPhone(const std::string& newPhone) { phone = newPhone; }
		void setDarkestSecret(const std::string& newSecret) { darkestSecret = newSecret; }
};

#endif