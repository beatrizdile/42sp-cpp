#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(){
	std::cout << "Welcome to crappy awesome PhoneBook!" << std::endl;
}

PhoneBook::~PhoneBook(){
}

void PhoneBook::phoneBookPrompt(){
	std::cout << std::endl << "Please, select one of the following commands:" << std::endl \
	<< "ADD	- to register a new contact" << std::endl \
	<< "SEARCH	- to search for a contact" << std::endl \
	<< "EXIT	- to quit the program" << std::endl;
}
