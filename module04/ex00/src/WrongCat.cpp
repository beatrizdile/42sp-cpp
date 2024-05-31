#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat& copy) : WrongAnimal(copy){
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat& other){
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other){
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "Wrong Meow Meow" << std::endl;
}
