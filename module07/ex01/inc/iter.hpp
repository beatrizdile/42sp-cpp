#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void iter(T* array, int size, void (*func)(const T&)) {
	for (int i = 0; i < size; i++) {
		func(array[i]);
	}
}

template <typename T, typename F>
void iter(T* array, int size, F func) {
	for (int i = 0; i < size; i++) {
		func(array[i]);
	}
}

void printInt(int x) {
    std::cout << "Integer: " << x << std::endl;
}

void printStr(std::string x) {
	std::cout << "String: " << x << std::endl;
}

void printDouble(double x) {
	std::cout << "Double: " << x << std::endl;
}

template <typename T>
void printElement(T element) {
    std::cout << "Element: " << element << std::endl;
}

#endif