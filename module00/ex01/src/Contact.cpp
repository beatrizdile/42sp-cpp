#include "Contact.hpp"
#include <iostream>

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
