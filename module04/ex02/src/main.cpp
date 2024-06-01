#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) 
{
	// PDF test
	// ----------------------------------------------
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// delete i;
	// ----------------------------------------------


	// Array of animals test 
	// ----------------------------------------------
	// Animal *array[100];
	// for(int i = 0; i < 100; i++)
	// {
	// 	if (i % 2 == 0)
	// 		array[i] = new Dog();
	// 	else
	// 		array[i] = new Cat();
	// }

	// for(int i = 0; i < 100; i++)
	// {
	// 	array[i]->makeSound();
	// }

	// for (int i = 0; i < 100; i++)
	// {
	// 	delete array[i];
	// }
	// ----------------------------------------------


	// Deep copy test 
	// ----------------------------------------------
	// std::cout << "--------------" << std::endl;
	// Cat cat;
	// Brain& catBrain = *cat.getBrain();
	// catBrain.setIdea(0, "I am a catttt");
	// std::cout << "Cat's idea: " << catBrain.getIdea(0) << std::endl;
	// std::cout << "Brain address: " << cat.getBrain() << std::endl;

	// std::cout << "--------------" << std::endl;

	// Cat cat2(cat);
	// Brain& cat2Brain = *cat2.getBrain();
	// std::cout << "Cat2's idea: " << cat2Brain.getIdea(0) << std::endl;
	// std::cout << "Brain address: " << cat2.getBrain() << std::endl;

	// std::cout << "--------------" << std::endl;
	// ----------------------------------------------

	// Shallow copy test
	// ----------------------------------------------
	// Dog basic;
	// std::cout << basic.getBrain() << std::endl;
	// {
	// 	Dog tmp = basic;
	// 	std::cout << tmp.getBrain() << std::endl;
	// }
	// ----------------------------------------------

	// Trying to instantiate the Animal abstract class
	// Animal animal; // Error: cannot instantiate abstract class

	return 0;
}
