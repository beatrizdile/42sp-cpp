#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) 
{
	std::cout << "------------------------------------" << std::endl;

	Animal bea("Beatriz");
	std::cout << "bea.getType(): " << bea.getType() << std::endl;
	std::cout << "Sound: ";
	bea.makeSound();

	std::cout << "------------------------------------" << std::endl;

	Dog dog;
	std::cout << "dog.getType(): " << dog.getType() << std::endl;
	std::cout << "Sound: ";
	dog.makeSound();

	std::cout << "------------------------------------" << std::endl;

	Cat cat;
	std::cout << "cat.getType(): " << cat.getType() << std::endl;
	std::cout << "Sound: ";
	cat.makeSound();

	std::cout << "------------------------------------" << std::endl;


	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "------------------------------------" << std::endl;

	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound(); //will output the wrongAnimal sound!

	std::cout << "------------------------------------" << std::endl;

	delete meta;
	delete j;
	delete i;
	delete wrongCat;

	return 0;
}

