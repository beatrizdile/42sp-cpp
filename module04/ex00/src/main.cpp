#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) 
{
	// Animal bea("Beatriz"); // Abstract class not allowed to instantiate
	// std::cout << "bea.getType(): " << bea.getType() << std::endl;

	std::cout << "------------------------------------" << std::endl;

	Dog dog("Dog");
	std::cout << "dog.getType(): " << dog.getType() << std::endl;
	std::cout << "Sound: ";
	dog.makeSound();

	std::cout << "------------------------------------" << std::endl;

	Cat cat("Cat");
	std::cout << "cat.getType(): " << cat.getType() << std::endl;
	std::cout << "Sound: ";
	cat.makeSound();

	std::cout << "------------------------------------" << std::endl;
}
