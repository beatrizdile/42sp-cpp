#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "VALUE AT THE TOP: " << std::endl;
	std::cout << mstack.top() << std::endl;
	std::cout << "POP TOP VALUE" << std::endl;
	mstack.pop();
	std::cout << "NEW VALUE AT THE TOP: " << std::endl;
	std::cout << mstack.top() << std::endl;

	std::cout << "SIZE OF THE STACK: " << std::endl;
	std::cout << mstack.size() << std::endl;

	std::cout << "----------------------" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);

	std::cout << "VALUE AT BEGINNING: " << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << *it << std::endl;
	std::cout << "VALUE AT ENDING: " << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << *(ite - 1) << std::endl;
	std::cout << "----------------------" << std::endl;

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// using stack's constructor works here because we inherited our MutantStack from std::stack
	std::stack<int> s(mstack);
	return 0;
}