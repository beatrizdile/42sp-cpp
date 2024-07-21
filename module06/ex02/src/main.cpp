#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	int random = rand() % 3;
	if (random == 0) {
		std::cout << "A created" << std::endl;
		return new A();
	} else if (random == 1) {
		std::cout << "B created" << std::endl;
		return new B();
	} else {
		std::cout << "C created" << std::endl;
		return new C();
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A identified" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B identified" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C identified" << std::endl;
	}

}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A identified" << std::endl;
		(void) a;
	} catch (std::exception &e) {
		try {
			B &b = dynamic_cast<B&>(p);
			std::cout << "B identified" << std::endl;
			(void) b;
		} catch (std::exception &e) {
			try {
				C &c = dynamic_cast<C&>(p);
				std::cout << "C identified" << std::endl;
				(void) c;
			} catch (std::exception &e) {
				std::cout << "Unknown" << std::endl;
			}
		}
	}

}

int main()
{
	srand(time(NULL));
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;    
}
