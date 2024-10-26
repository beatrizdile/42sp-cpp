#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <vector>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _vec;
        Span();
    public:
        Span(unsigned int n);
        Span(Span const &other);
        Span &operator=(Span const &other);
        ~Span();
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        
        void assign(std::vector<int>::iterator it1, std::vector<int>::iterator it2); 
};

#endif