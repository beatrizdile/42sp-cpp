#include "Contact.hpp"

Contact::Contact(const std::string& first, const std::string& last,
	const std::string& nick, const std::string& phone, const std::string& secret){
		this->firstName = first;
		this->lastName = last;
		this->nickname = nick;
		this->phone = phone;
		this->darkestSecret = secret;
}

Contact::~Contact(){
}

static std::string truncateText(const std::string& text) {
    if (text.length() > 10) {
        return text.substr(0, 9) + ".";
    } else {
        return text;
    }
}

void Contact::displayContactRow(size_t index) {
    std::cout << "|" << std::setw(10) << index << "|" << std::setw(10)
              << truncateText(firstName) << "|" << std::setw(10)
              << truncateText(lastName) << "|" << std::setw(10)
              << truncateText(nickname) << "|" << std::endl;
}

void Contact::displayContact(void) {
    std::cout << std::endl
              << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phone << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl << std::endl;
}
