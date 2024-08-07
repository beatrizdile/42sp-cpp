#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(Serializer& copy);
		Serializer& operator=(Serializer& other);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif