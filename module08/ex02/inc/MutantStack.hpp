#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {};
        MutantStack(MutantStack const &other) : std::stack<T>(other) {};
        MutantStack &operator=(MutantStack const &other) { std::stack<T>::operator=(other); return (*this); };
        ~MutantStack() {};

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin()
    { return (std::stack<T>::c.begin()); };

    iterator end()
    { return (std::stack<T>::c.end()); };
};

#endif